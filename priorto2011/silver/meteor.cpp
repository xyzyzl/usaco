#include <bits/stdc++.h>

using namespace std;

int M;
int hit_t[350][350];
bool vis[350][350];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {

	// preset
	for(int i = 0; i < 350; i++){
		for(int j = 0; j < 350; j++){
			hit_t[i][j] = pow(2, 30);
			vis[i][j] = false;
		}
	}

	// input
	cin >> M;
	for(int i = 0; i < M; i++){
		int xi, yi, ti;
		cin >> xi >> yi >> ti;
		hit_t[xi][yi] = min(ti, hit_t[xi][yi]);

		for(int i = 0; i < 4; i++){
			if(xi + dx[i] >= 0 && xi + dx[i] < 350 &&
				yi + dy[i] >= 0 && yi + dy[i] < 350)
				hit_t[xi+dx[i]][yi+dy[i]] = min(ti, hit_t[xi+dx[i]][yi+dy[i]]);
		}
	}

	// bfs: typical bfs except if the distance to a point is more
	// than the kill time there's no point in going there
	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(0, make_pair(0, 0)));
	vis[0][0] = true;

	while(!q.empty()){
		pair<int, pair<int, int> > pos = q.front();
		q.pop();
		int t = pos.first;
		int x = pos.second.first;
		int y = pos.second.second;
		if(hit_t[x][y] > 1001){
			cout << t << endl;
			return 0;
		}
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= 350 || ny < 0 || ny >= 350 || vis[nx][ny])
				continue;
			if(t+1 >= hit_t[nx][ny])
				continue;
			// cout << nx + ny << endl;
			vis[nx][ny] = true;
			q.push(make_pair(t+1, make_pair(nx, ny)));
		}
	}

	cout << -1 << endl;

}
