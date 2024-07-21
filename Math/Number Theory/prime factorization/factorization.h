#include<iostream>
#include<vector>
#include<map>
//you may use unordered_map instead of map for better performance
using namespace std;
vector<int>primes;
bool vis[500010];
void p(int n){
  for(int i=2;i<=n;i++){
    if(vis[i]==false)
    primes.push_back(i);
    for(int j=0;i*primes[j]<=n;j++){      
      vis[primes[j]*i]=true;
      if(i%primes[j]==0)break;
    }
  }
}
map<int,int>prime_factors(int n){
    p(n);
    map<int,int>res;
    for(auto p:primes){
      while(n%p==0){
        n/=p;
        res[p]++;
      }
    }
    return res;
}