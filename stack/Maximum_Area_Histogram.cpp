// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> NearestSmallestToLeft(vector<int> &v){
    stack<pair<int,int>> s;
    vector<int> ans;
    int pseudo_element = -1;

    for(int i=0; i<v.size(); i++){
        if(s.empty())
            ans.push_back(pseudo_element);
        else if(s.top().first<v[i])
            ans.push_back(s.top().second);
        else if(s.top().first>=v[i]){
            while(!s.empty() && s.top().first>=v[i])
                s.pop();
            if(s.empty())
                ans.push_back(pseudo_element);
            else
                ans.push_back(s.top().second);
        }
        s.push({v[i], i});
    }
    return ans;
}

vector<int> NearestSmallestToRight(vector<int> &v){
    stack<pair<int,int>> s;
    vector<int> ans;
    int pseudo_element = v.size();

    for(int i=v.size()-1; i>=0; i--){
        if(s.empty()){
            ans.push_back(pseudo_element);
        }
        else if(s.top().first<v[i]){
            ans.push_back(s.top().second);
        }
        else if(s.top().first>=v[i]){
            while(!s.empty() && s.top().first>=v[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(pseudo_element);
            }
            else{
                ans.push_back(s.top().second);
            }
        }
        s.push({v[i], i});
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int MaximumAreaHistogram(vector<int> &v){
    vector<int> left = NearestSmallestToLeft(v);
    vector<int> right = NearestSmallestToRight(v);

    vector<int> width(v.size()), area(v.size());

    int mxArea=INT_MIN;

    for(int i=0; i<v.size(); i++){
        width[i]=right[i]-left[i]-1;
        area[i]=width[i]*v[i];
        mxArea=max(mxArea,area[i]);
    }
    return mxArea;
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
    int ans = MaximumAreaHistogram(v);
    cout<<endl;
    cout<<"Largest Rectangular Area in a Histogram: "<<ans<<endl;
}
