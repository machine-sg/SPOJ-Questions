#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
 
vector<int> ar[1000001];
bool vis[1000001];
 
 
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
int n;
bool isCyclicUtil(int v, int parent) 
{ 
    // Mark the current node as visited 
    vis[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
  //  list<int>::iterator i; 
    for (auto i:ar[v]) 
    { 
        // If an adjacent is not visited, then recur for  
        // that adjacent 
        if (!vis[i]) 
        { 
           if (isCyclicUtil(i,  v)) 
              return true; 
        } 
  
        // If an adjacent is visited and not parent of current 
        // vertex, then there is a cycle. 
        else if (i != parent) 
           return true; 
    } 
    return false; 
} 
 
bool isTree() 
{ 
    // Mark all the vertices as not visited and not part of  
    // recursion stack 
  //  bool visited[n]; 
    for (int i = 1; i <=n; i++) 
        vis[i] = false; 
  
    // The call to isCyclicUtil serves multiple purposes. 
    // It returns true if graph reachable from vertex 0  
    // is cyclcic. It also marks all vertices reachable  
    // from 0. 
    if (isCyclicUtil(1,  0)) 
             return false; 
  
    // If we find a vertex which is not reachable from 0  
    // (not marked by isCyclicUtil(), then we return false 
    for (int u = 1; u <= n; u++) 
        if (!vis[u]) 
           return false; 
  
    return true; 
} 
 
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int m;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        ar[u].pb(v);
        ar[v].pb(u);
    }
    if(isTree())
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
   // if(dfs(1,0)==false && m==n-1)cout<<"YES"<<endl;
    //else cout<<"NO"<<endl;
} 
