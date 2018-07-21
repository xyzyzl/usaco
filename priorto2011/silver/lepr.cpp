#include <iostream>

using namespace std;

#define MAXN 800
#define MINN -1000000000

int N, torus[MAXN][MAXN], arr[MAXN], tot = MINN;

void special() {
  int sum=0,neg=0;
  for (int i=0; i<N; i++){
    sum+=arr[i];
    if (neg>sum)
      neg=sum;
    if (sum>0)
      sum=0;
  }
  sum=0;
  for (int i=0; i<N; sum+=arr[i++]);
  if (sum!=neg)
    sum-=neg;
  if (tot<sum)
    tot=sum;
}

void scan() {
  int sum=MINN;
  for (int i=0,x=0,t=0; i<x+N; i++) {
  t+=arr[i%N];
    if (sum<t)
      sum=t;
    if (t<0){
      if (i>=N)
        break; 
      else{
        t=0;
        x=i+1;
      }
    }
  }
  if (tot<sum)
    tot=sum;
}

void solve(int dir) {
  for (int i=0; i<N; i++) {
    int y=dir==2 ? 0 : i;
    int x=dir==2 ? i : 0;
      for (int j=0; j<N; j++){
        arr[j]=torus[y][x];
        if (dir==1 || dir==3){
          x=(x+1)%N;
        }
        else if (dir==4) {
          x=(x-1+N)%N;
        }
        if (dir>1)
          y=(y+1)%N;
      }
    scan();
    special();
  }
}

int main() {
  
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> torus[i][j];
    }
  }
  for(int i = 1; i <= N; solve(i++)){
  }
  cout << tot << endl;
}
