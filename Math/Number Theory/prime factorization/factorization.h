#include<iostream>
#include<vector>
#include<map>
//you may use unordered_map instead of map for better performance
using namespace std;
vector<int>primes;
bool vis[500010];
map<int,int>prime_factors(int n){
    map<int,int>res;
    for(int p=2;p*p<=n;p++){
      while(n%p==0){
        n/=p;
        res[p]++;
      }
    }
    if(n>1) res[n]++;
    return res;
}