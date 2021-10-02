// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
// https://www.youtube.com/watch?v=ZmnqCZp9bBs

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> &v){
    stack<int> s;
    int area=0,maxArea=-1,i;

    for(int i=0; i<v.size();){
        if(s.empty() || v[i]>=v[s.top()]){
            s.push(i++);
        }
        else{
            int top = s.top();
            s.pop();
            if(s.empty())
                area=v[top]*i;
            else
                area=v[top]*(i-s.top()-1);

            if(maxArea<area)
                maxArea=area;
        }
    }
    while(!s.empty()){
        int top = s.top();
        s.pop();
        if(s.empty())
            area=v[top]*i;
        else
            area=v[top]*(i-s.top()-1);

        if(maxArea<area)
                maxArea=area;
    }
    return maxArea;
}

int main() {
     int n;
    cout<<"Enter no. of element: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter Elements : ";
    for(auto &x : v){
        cin>>x;
    }
    int ans = getMaxArea(v);
    cout<<endl;
    cout<<"Largest Rectangular Area in a Histogram: "<<ans<<endl;
}
