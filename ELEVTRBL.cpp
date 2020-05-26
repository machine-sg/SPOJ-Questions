#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007

//vector<int> ar[1000001];


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
int f, src, dest, up, down, moves;
int vis[1000001];
int dist[1000001];

void bfs()
{
    int cur, nextUp, nextDown;
    queue<int> q;
    vis[src] = 1;
    dist[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        nextUp = cur + up;
        nextDown = cur - down;
        if(nextUp<=f && !vis[nextUp])
        {
            vis[nextUp] = 1;
            dist[nextUp] = dist[cur]  + 1;
            q.push(nextUp);
        }
        if(nextDown>=1 && !vis[nextDown])
        {
            vis[nextDown] = 1;
            dist[nextDown] = dist[cur]  + 1;
            q.push(nextDown);
        }
    }
}

int main()
{
    cin>>f>>src>>dest>>up>>down;
    
    dist[dest] = -1;
    bfs();
    if(dist[dest] == -1)
    {
        cout<<"use the stairs";
    }
    else
    {
        cout<<dist[dest];
    }

}
