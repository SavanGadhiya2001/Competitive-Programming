#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> NearestSmallestToLeft(vector<int> &v){
    stack<int> s;
    vector<int> ans;

    for(int i=0; i<v.size(); i++){
        if(s.empty())
            ans.push_back(-1);
        else if(s.top()<v[i])
            ans.push_back(s.top());
        else if(s.top()>=v[i]){
            while(!s.empty() && s.top()>=v[i])
                s.pop();
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(v[i]);
    }
    return ans;
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
    vector<int> ans = NearestSmallestToLeft(v);
    for(auto &x : ans)
        cout<<x<<" ";
}
