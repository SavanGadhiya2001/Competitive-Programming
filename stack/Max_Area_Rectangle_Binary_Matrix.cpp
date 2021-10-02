// https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
// https://www.youtube.com/watch?v=St0Jf_VmG_g&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=8&t=10s

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

bool sortByMaxMultiplication(const pair<int,int> &a, const pair<int,int> &b) {
    //cout<<"called\n";
    return (a.first*a.second > b.first*b.second);
}

vector<int> MaximumAreaHistogram(vector<int> &v){
    vector<int> left = NearestSmallestToLeft(v);
    vector<int> right = NearestSmallestToRight(v);

    vector<int> width(v.size()), area(v.size());

    int mxArea=INT_MIN;
    vector<pair<int, int>> vp;

    for(int i=0; i<v.size(); i++){
        width[i]=right[i]-left[i]-1;
        area[i]=width[i]*v[i];

        // mxArea=max(mxArea,area[i]);
        if(mxArea<area[i]){
            mxArea=area[i];
            vp.push_back({v[i], width[i]});
        }
    }
    sort(vp.begin(), vp.end(), sortByMaxMultiplication);


    vector<int> t;     // (no.of rows, no.of columns, mxArea)
    t.push_back(vp[0].first);  // no.of rows
    t.push_back(vp[0].second); // no.of columns
    t.push_back(mxArea);       // mxArea
    return t;
}

int Max_Area_Rectangle_In_Binary_Matrix(vector<vector<int>> &v){
    // n*m matrix
    int n=v.size();
    int m=v[0].size();
    vector<int> temp;
    //vector<pair<int,int>> ansMatrix=({0,0});
    pair<int, int> ansMatrix(0, 0);

    for(int j=0; j<m; j++)
        temp.push_back(v[0][j]);
    vector<int> ans = MaximumAreaHistogram(temp);
    ansMatrix.first=ans[0];  // no.of rows
    ansMatrix.second=ans[1]; // no.of columns

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]==0)
                temp[j]=0;
            else
                temp[j]=temp[j]+v[i][j];
        }

         vector<int> tmp = MaximumAreaHistogram(temp);

        // ans=max(ans, tmp);
        if(ans[2]<tmp[2]){
            ans[2]=tmp[2];           // mxArea
            ansMatrix.first=tmp[0];  // no.of rows
            ansMatrix.second=tmp[1]; // no.of columns
        }
    }
    //cout<<"ansMatrix.first: "<<ansMatrix.first<<endl;
    //cout<<"ansMatrix.second: "<<ansMatrix.second<<endl;

    cout<<"\nMaximum Area Rectangle Matrix:\n";
    for(int i=0; i<ansMatrix.first; i++){
        for(int j=0; j<ansMatrix.second; j++){
            cout<<1<<" ";
        }
        cout<<endl;
    }

    return ans[2];
}

int main() {
    int n,m;
    cout<<"Enter n and m for matrix: ";
    cin>>n>>m;
    vector<vector<int>> v;
    cout<<"Enter Elements :\n";
    for(int i=0; i<n; i++){
            vector<int> row;
        for(int j=0; j<m; j++){
            int a;  cin>>a;
            row.push_back(a);
        }
        v.push_back(row);
    }
    int ans = Max_Area_Rectangle_In_Binary_Matrix(v);
    cout<<endl;
    cout<<"Max Area Rectangle in Binary Matrix: "<<ans<<endl;
}
