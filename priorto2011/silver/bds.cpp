#include <iostream>
#include <algorithm>

using namespace std;

int N, S; 
int pas[11][11];

int fact(int k) {
	int res = 1;
	for(int i = 1; i <= k; i++){
		res *= i;
	}
	return res;
}

int comb(int n, int k){
	// cout << (fact(n))/(fact(k)*fact(n-k)) << endl;
	return (fact(n))/(fact(k)*fact(n-k));
}

void get_pas(){

	for(int i = 0; i <= 10; i++){
		for(int j = 0; j <= i; j++){
			pas[i][j] = comb(i, j);
		}
	}

}

int main() {
	
	cin >> N >> S;
	int num_of_ways = fact(N);

	int arr[N];

	for(int i = 0; i < N; i++){
		arr[i] = i+1;
	}

	get_pas();

	for(int i = 0; i < num_of_ways; i++){
		// somehow check the current permutation
		int sum = 0;
		for(int j = 0; j < N; j++){
			sum += arr[j] * pas[N-1][j];
		}

		if(sum == S){
			for(int j = 0; j < N-1; j++){
				cout << arr[j] << " ";
			}
			cout << arr[N-1] << endl;
			return 0;
		}

		// get the next permutation
		next_permutation(arr, arr+N);
	}

	return 0;

}
