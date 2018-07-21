#include <bits/stdc++.h>

#define MAXN 80010
#define INF 1000000010

int N;
long long h[MAXN];

using namespace std;

typedef pair<long long, int> pli;

int main() {

	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> h[i];
	}
	h[N] = INF;

	// all cows that can see their spot right now
	stack<pli> can_see;
	can_see.push(make_pair(h[0], 0));

	long long sm = 0;

	for(int i = 0; i < N; i++){
		while(!can_see.empty() && can_see.top().first <= h[i+1]){
			sm += i-can_see.top().second;
			// cout <<  i-can_see.top().second << " " << i + 1 << endl;
			can_see.pop();
		}
		can_see.push(make_pair(h[i+1], i+1));
		// cout << "hi" << endl;
	}

	cout << sm << endl;

}
