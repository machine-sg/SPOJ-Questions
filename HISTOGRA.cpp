#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define MODC 1000000007
#define pi pair<int,int>
#define mp make_pair

void largestRectanglularAreaInHistogram(int hist[],int n) {
    stack<int> s;

    int maxArea = 0;
    int tp;
    int areaWithTop;

    int i = 0;
    while (i <n) {
        if (s.empty() || hist[s.top()] <= hist[i]) {
            s.push(i++);
        } else {
            tp = s.top();
            s.pop();
            int w = s.empty() ? i : i - s.top() - 1;
            areaWithTop = hist[tp] * w;

            if (maxArea < areaWithTop)
                maxArea = areaWithTop;
        }
    }

    while (!s.empty()) {
        tp = s.top();
        s.pop();
        int w = s.empty() ? i : i - s.top() - 1;
        areaWithTop = hist[tp] * w;

        if (maxArea < areaWithTop)
            maxArea = areaWithTop;
    }

    cout<<maxArea<<endl;
}


int main(){
    int n;
    while(1){
    cin>>n;
	if(n==0)
		break;
    int hist[n];
    for(int i=0;i<n;i++)cin>>hist[i];
    largestRectanglularAreaInHistogram(hist,n);
    }
    return 0;
    
}
