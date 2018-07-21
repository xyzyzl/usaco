#include <bits/stdc++.h>

#define x first
#define y second

#define MAXN 30

using namespace std;

typedef stack<int> sti;
typedef queue<int> qi;
typedef set<int> si;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
#define x first
#define y second

int dx[8] = {1, 2, -1, -2, 1, -1, -2, 2};
int dy[8] = {2, 1, -2, -1, -2, 2, 1, -1};

int M, N;
bool vis[30][30];
pii s, e;

pair<pii, long long> best[30][30];

struct Node {

	int i, j;
	int lily, jumps;
	long long ways;

	Node(int l, int jm, long long w, int _i, int _j) {
		lily = l;
		jumps = jm;
		ways = w;
		i = _i;
		j = _j;
	}

	// flip the signs to process priority_queue in correct order
	bool operator< (Node nd) const {

		if(lily == nd.lily){
			if(jumps == nd.jumps){
				return ways < nd.ways;
			}
			return jumps > nd.jumps;
		}
		return lily > nd.lily;

	}

};

int pond[MAXN][MAXN];

priority_queue<Node> bfs;

int main() {

	cin >> M >> N;
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			cin >> pond[i][j];

			// check start, end
			if(pond[i][j] == 3)
				s = make_pair(i, j);
			if(pond[i][j] == 4)
				e = make_pair(i, j);
		}
	}

	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			best[i][j] = make_pair(make_pair(-1, -1), 0);
		}
	}

    bfs.push(Node(0, 0, 1, s.x, s.y));
    best[s.x][s.y] = make_pair(make_pair(0, 0), 1);

	// cout << best[e.x][e.y].x.x << endl;

    while(!bfs.empty()) {
		Node nd = bfs.top();
		bfs.pop();

		if(vis[nd.i][nd.j]) {
			continue;
		}
		vis[nd.i][nd.j] = true;

		for(int i = 0; i < 8; i++) {
			int nx = nd.i + dx[i];
			int ny = nd.j + dy[i];
			int nl = nd.lily + (pond[nx][ny] == 1 ? 0 : 1);

			if(0 <= nx && nx < M && 0 <= ny && ny < N && !vis[nx][ny] && pond[nx][ny] != 2) {
				if(best[nx][ny].x.x == -1 || nl < best[nx][ny].x.x) {
					best[nx][ny].x.x = nl;
					best[nx][ny].x.y = nd.jumps+1;
					best[nx][ny].y = nd.ways;
					bfs.push(Node(best[nx][ny].x.x, best[nx][ny].x.y, best[nx][ny].y, nx, ny));
					continue;
				}
				else if(nl == best[nx][ny].x.x && (best[nx][ny].x.y == -1 || nd.jumps+1 < best[nx][ny].x.y)) {
					best[nx][ny].x.x = nl;
					best[nx][ny].x.y = nd.jumps+1;
					best[nx][ny].y = nd.ways;
					bfs.push(Node(best[nx][ny].x.x, best[nx][ny].x.y, best[nx][ny].y, nx, ny));
					continue;
				}
				else if(nl == best[nx][ny].x.x && nd.jumps+1 == best[nx][ny].x.y) {
					best[nx][ny].y += nd.ways;
					bfs.push(Node(best[nx][ny].x.x, best[nx][ny].x.y, best[nx][ny].y, nx, ny));
					continue;
				}
			}
		}
    }

	if(best[e.x][e.y].x.x == -1) {
		cout << -1 << endl;
	}
	else {
		cout << best[e.x][e.y].x.x-1 << endl;
		cout << best[e.x][e.y].x.y << endl;
		cout << best[e.x][e.y].y << endl;
	}

}
