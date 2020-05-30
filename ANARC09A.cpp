#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
#define pi pair<int,int>
#define mp make_pair

int main()
{
  int k=0,ans,o,c;
  while(1)
  {
    char s[2001];
    scanf("%s",s);
    if(s[0]=='-')
      break;
    o = c = 0;
    int i = 0;
    while(s[i]!='\0')
    {
      if(s[i]=='{')
        o++;
      else
      {
        o--;
        if(o<0)
        {
          o=1;
          c++;
        }
      }
      i++;
    }
    ans = c+o/2;
    cout<<k+1<<". "<<ans<<endl;
    k++;
  }
  return 0;
}
