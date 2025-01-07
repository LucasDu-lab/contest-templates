#include<iostream>
#include<vector>
using namespace std;
int n,m,s,par[500010][20],dep[500010],cost[500010][20],path[500010];
vector<int>adj[500010];
//the second dimension of these arrays is ceil(log2(n)+1)
//table of common exponents:
/*
2^17=131072
2^19=524288
2^20=1048576
2^23=8388608
2^24=16777216
*/

/// @brief initiation of arrays, must be called
/// @param s current node
/// @param e parent of s, if s is the root node, set e to 0
void dfs(int s, int e) {
  par[s][0]=e;
  dep[s]=dep[e]+1;
  for(int i=1;i<=19;i++){//2^19=524288
    par[s][i]=par[par[s][i-1]][i-1];
    //cost[s][i] = cost[par[s][i - 1]][i - 1] + cost[s][i - 1];
  }
  for(auto u:adj[s]){
    if(u==e)continue;    
    //cost[u][0] = 1;
    dfs(u,s);
  }  
}

/// @brief find the lowest common ancestor of two nodes
/// @param x the first node
/// @param y the second node
/// @return the index of the node of the lowst common ancestor
int lca(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  int tmp = dep[y] - dep[x], ans = 0;
  for (int j = 0; tmp; ++j, tmp >>= 1)
    if (tmp & 1) ans+=(1<<j), y = par[y][j];
  if (y == x) return y;
  
  for (int j = 19; j >= 0 && y != x; --j) {//2^19=524288
    if (par[x][j] != par[y][j]) {
      ans += (1<<j)*2;
      x = par[x][j];
      y = par[y][j];
    }
  }
  
  return par[x][0];
}
/*
Possible main function:
remember to add adj[0]={0}; to the main function
n is number of nodes
m is number of queries
s is the root of the tree
int main(){
  cin>>n>>m>>s;
  adj[0]={0};
  for(int i=1;i<n;i++){
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
  dfs(s,0);
  while(m--){
      int a,b;
      cin>>a>>b;
      cout<<lca(a,b)<<"\n";
  }
  return 0;
}
*/