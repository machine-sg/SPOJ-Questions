#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define modulo 1000000007 
 
vector<int> ar[100001];
int vis[100001];
int col[100001];
 
ll cc_count=0;
bool dfs(int node, int color){
    vis[node]=1;
     col[node]=color;
     for(auto child:ar[node]){
         if(vis[child]==0){
             bool res=dfs(child , color^1);
             if(res==false)
                return false;
         }
         else if(col[node]==col[child]){
             return false;
         }
     }
   return true;
}
int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            ar[i].clear(), vis[i]=0;
        }
        int a,b;
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                bool res=dfs(i,0);
                if(res==false){
                    flag=false;
                }
            }
        }
        cout<<"Scenario #"<<tc<<":"<<endl;
        if(flag==true){
            cout<<"No suspicious bugs found!"<<endl;
        }
        else cout<<"Suspicious bugs found!"<<endl;
    }
    return 0;
} 
