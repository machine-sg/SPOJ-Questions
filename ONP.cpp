#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
#define pi pair<int,int>
#define mp make_pair


int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string str;
        cin>>str;
        int n=str.size();
        queue<char> s;
        stack<char> t;
        string ans1="",ans="";
        for(int i=0;i<n;i++){
            if(str[i]=='(')
                t.push(str[i]);
            else if( str[i]>='a' && str[i]<='z'){
                s.push(str[i]);
            }
            else if(str[i]=='*' || str[i]=='+' ||str[i]=='-' || str[i]=='/' || str[i]=='^'){
                t.push(str[i]);
            }
            else if(str[i]==')'){
                while(!t.empty()){
                    
                            if(t.top()!='('){
                            s.push(t.top());
                            t.pop();
                            }
                            else{
                                t.pop();
                               // continue;
                                break;
                            }
                    }
                   
                }
               
        }
        while(!t.empty()){
            s.push(t.top());
            t.pop();
        }
        while(!s.empty()){
            ans+=s.front();
            s.pop();
        }
        cout<<ans<<'\n';
    }
}
