#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second

int N, M;
#define MAXN 10001
vector<pii> adj_lst[3][MAXN];
int d[3][MAXN];
int dickstraw(int i1, int i2, int st) {
  for(int i = 0; i < N; i++) {
    d[i2][i] = INT_MAX;
  }
  d[i2][st] = 0;
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(pii(0, st));
  while(!pq.empty()) {
    int ind = pq.top().y;
    int val = pq.top().x;
    pq.pop();
    if(val != d[i2][ind])
      continue;
    for(int i = 0; i < adj_lst[i1][ind].size(); i++) {
      int nxt = adj_lst[i1][ind][i].x;
      int boi = adj_lst[i1][ind][i].y + d[i2][ind];
      if(boi < d[i2][nxt]) {
	d[i2][nxt] = boi;
	pq.push(make_pair(d[i2][nxt], nxt));
      }
    }
  }
  return d[i2][N-1];
}

int main() {
  freopen("gpsduel.in", "r", stdin);
  freopen("gpsduel.out", "w", stdout);
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    int p, q;
    cin >> p >> q;
    adj_lst[0][b].push_back(make_pair(a, p));
    adj_lst[1][b].push_back(make_pair(a, q));
