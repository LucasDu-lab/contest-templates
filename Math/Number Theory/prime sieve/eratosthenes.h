#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
bool vis[100010];
vector<int> primes;
void p(int n){
  for(int i=2;i<=n;i++){
    if(vis[i])continue;
    primes.push_back(i);
    for(int j=2*i;j<=n;j+=i){
      vis[j]=true;
    }
  }
}