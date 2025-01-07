#include<iostream>
#include<vector>
using namespace std;
int n,m,s,par[500010][20],dep[500010],cost[500010][20],path[500010];
vector<int>adj[500010],weight[500010]; 
void dfs(int s, int e) {
  par[s][0]=e;
  dep[s]=dep[e]+1;
  for(int i=1;i<=19;i++){
    par[s][i]=par[par[s][i-1]][i-1];
    cost[s][i] = cost[par[s][i - 1]][i - 1] + cost[s][i - 1];
  }
  for(int i=0;i<adj[s].size();i++){
      if(adj[s][i]==e)continue;
      cost[adj[s][i]][0]=weight[s][i];
      dfs(adj[s][i],s);
  }  
}


int lca(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  int tmp = dep[y] - dep[x], ans = 0;
  for (int j = 0; tmp; ++j, tmp >>= 1)
    if (tmp & 1) ans+=cost[y][j], y = par[y][j];
  if (y == x) return ans;
  
  for (int j = 19; j >= 0 && y != x; --j) {
    if (par[x][j] != par[y][j]) {
      ans += cost[x][j]+cost[y][j];
      x = par[x][j];
      y = par[y][j];
    }
  }
  
  return ans+cost[x][0]+cost[y][0];
}
/*
int main(){
  cin>>n>>m;
  s=1;
  adj[0]={0};
  for(int i=1;i<n;i++){
      int a,b,w;
      cin>>a>>b>>w;
      adj[a].push_back(b);
      adj[b].push_back(a);
      weight[a].push_back(w);
      weight[b].push_back(w);
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