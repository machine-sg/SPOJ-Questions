#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define pb push_back

vector<int> ar[1000001];
int vis[1000001];
int dist[1000001];
vector<int> primes;
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

bool isValid(int a,int b){
    int cnt=0;
    while(a>0){
        if(a%10 !=b%10){
            cnt++;
        }
        a/=10, b/=10;
    }
    if(cnt==1)return true;
    else return false;
}
void buildGraph(){
    for(int i=1000;i<=9999;i++){
        if(isPrime(i)){
            primes.pb(i);
        }
    }
    
    for(int i=0;i<primes.size();i++){
        for(int j=i+1;j<primes.size();j++){
            int a=primes[i];
            int b=primes[j];
            
            if(isValid(a,b)){
                ar[a].pb(b);
                ar[b].pb(a);
            }
        }
    }
}
void bfs(int node){
    queue<int> q;
    q.push(node);
    dist[node]=0;
    vis[node]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto child:ar[x]){
            if(vis[child]==0){
                vis[child]=1;
                dist[child]=dist[x]+1;
                q.push(child);
            }
        }
    }
}
int main(){
    int t,a,b;
    cin>>t;
    buildGraph();
    while(t--){
        cin>>a>>b;
        for(int i=1000;i<=9999;i++){
            dist[i]=-1;
            vis[i]=0;
        }
        bfs(a);
        if(dist[b]==-1){
            cout<<"Impossible"<<endl;
        }
        else cout<<dist[b]<<endl;
    }
}
