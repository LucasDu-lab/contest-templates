#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> primes;
bool vis[1000010];
void p(int n){ //calculate prime numbers up to n
  for(int i=2;i<=n;i++){
    if(vis[i]==false)
    primes.push_back(i);
    for(int j=0;i*primes[j]<=n;j++){      
      vis[primes[j]*i]=true;
      if(i%primes[j]==0)break;
    }
  }
}