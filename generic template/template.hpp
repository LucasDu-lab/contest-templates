#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using lll=__int128;
void setIO(string filename=""){
    if(filename.size()){
        freopen((filename+".in").c_str(),"r",stdin);
        freopen((filename+".out").c_str(),"w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
}
#define all(x) x.begin(),x.end()
#define endl "\n"
/*#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")*/ //include on CodeForces if TLE, may cause runtime error if not on cf
//#define ((a)%(b)) (((a)%(b)+(b))%(b)) //not sure if it works
#define sz(x) (int)((x).size())
#define mp make_pair
#define pb push_back
const int MOD=1e9+7,INF=0x3f3f3f3f,INT=2147483647;
