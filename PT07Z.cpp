#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007

vector<int> ar[1000001];
int visit[1000001];
int dist[1000001];

/*bool dfs(int node,int parent){
   vis[node]=1;
   for(auto child:ar[node]){
       if(vis[child]==0){
           if(dfs(child,node)==true)
            return true;
       }
       else if(child!=parent){
           return true;
       }
   }
   return false;
}*/
int ans;
int bfs(int x)
{
    queue<int> q;
    q.push(x);
    memset(visit,0,sizeof(visit));
    memset(dist,0,sizeof(dist));
    visit[x]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(auto i:ar[x])
        {
            if(!visit[i]){
                visit[i]=1;
                q.push(i);
                dist[i]=dist[x]+1;
            }
        }
    }
    int nodeIdx = max_element(dist, dist+1000001)-dist;
    ans=dist[nodeIdx];
    return nodeIdx;
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
   int n;
    int u,v;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        ar[u].pb(v);
        ar[v].pb(u);
    }
    bfs(bfs(1));
    cout<<ans<<endl;
    return 0;
}
