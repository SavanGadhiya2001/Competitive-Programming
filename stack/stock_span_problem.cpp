// https://www.geeksforgeeks.org/the-stock-span-problem/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> StockSpan(vector<int> &v){
    vector<int> ans;
    stack<pair<int, int>> s;  // {number, index}

    for(int i=0; i<v.size(); i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(s.top().first>v[i]){
            ans.push_back(s.top().second);
        }
        else if(s.top().first<=v[i]){
            while(!s.empty() && s.top().first<=v[i])
                s.pop();
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top().second);
        }
        s.push({v[i], i});
    }
    for(int i=0; i<ans.size(); i++)
        ans[i]=i-ans[i];
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
    vector<int> ans = StockSpan(v);
    for(auto &x : ans)
        cout<<x<<" ";
}
