#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
#define pi pair<int,int>
#define mp make_pair


int main(){
    string str;
    cin>>str;
    int len=str.size();
    stack<int> s;
    for(int i=0;i<len;i++){
        if(str[i]=='('){
            s.push(-1);
        }
        else if(str[i]==')'){
            int x=0;
            while(s.top()!=-1){
                x+=s.top();
                s.pop();
            }
            s.pop();
            s.push(x);
        }
        else if(isdigit(str[i])){
            int x=s.top();
            s.pop();
            s.push(x*(int)(str[i]-'0'));
        }
        else if(isalpha(str[i])){
            if(str[i]=='C'){
                s.push(12);
            }
            else if(str[i]=='O'){
                s.push(16);
            }
            else{
                s.push(1);
            }
        }
    }
    int sum=0;
    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    cout<<sum<<endl;
    return 0;
    
}
