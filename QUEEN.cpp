#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007

int X[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int Y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n,m;
char str[1005][1005];
int dist[1000][1000];
    
bool check(pair<int,int> t)
{
 if(t.first >=0 && t.first <n && t.second >=0 && t.second <m  && str[t.first][t.second] != 'X')
  return true;
 return false;
}

int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
 {
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++)
   scanf("%s", str[i]);
  queue<pair<int,int>> q;
  pair<int,int> start, final;
  for(int i=0; i<n; i++)
  {
   for(int j=0; j<m; j++)
   {
    dist[i][j] = 0;
    if(str[i][j] == 'S')
    {
     start.first= i;
     start.second = j;
     dist[i][j] = 1;
    }
    else if(str[i][j] == 'F')
    {
     final.first = i;
     final.second = j;
    }
   }
  }
  q.push(start);
  while(!q.empty())
  {
   pair<int,int> temp = q.front(), copy;
   q.pop();
   for(int i=0; i<8; i++)
   {
    copy = temp;
    copy.first += X[i];
    copy.second += Y[i];
    while(check(copy))
    {
     if(dist[copy.first][copy.second] == 0) {
      dist[copy.first][copy.second] = dist[temp.first][temp.second] + 1;
      q.push(copy);
     }
     else if(dist[copy.first][copy.second] != dist[temp.first][temp.second]+1)
      break; 
     copy.first += X[i];
     copy.second += Y[i];
    }
   }
  }
  cout << dist[final.first][final.second]-1 << endl;

 }
 return 0;
}
