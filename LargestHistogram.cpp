void largestRectanglularAreaInHistogram(int hist[],int n) {
    stack<int> s;

    int maxArea = 0;
    int tp;
    int areaWithTop;

    int i = 1;
    while (i <=n) {
        if (s.empty() || hist[s.top()] <= hist[i]) {
            s.push(i);i++;
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

