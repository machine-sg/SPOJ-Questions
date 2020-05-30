#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
#define pi pair<int,int>
#define mp make_pair


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int i,j;
        for(i=0;i<n;i++)cin>>a[i];
        for(i=n-2;i>=0;i--){
        if( a[i]<a[i+1] )
	        break;
        }
    if( i==-1 ){
      printf("%d\n",-1);
      continue;
    }
    for(j=i+1;j<n;j++){
      if( a[j]<=a[i] )
	break;
    }
    swap(a[i],a[j-1]);
    sort(a+i+1,a+n);
    for(i=0;i<n;i++)
      printf("%d",a[i]);
    printf("\n");
  }
    
    return 0;
}
