// https://www.geeksforgeeks.org/trapping-rain-water/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int RainWaterTrapping(vector<int> &v) {

	if(v.size()==0 || v.size()==1)
        return 0;

	vector<int> maxL(v.size(), 0);
	vector<int> maxR(v.size(), 0);
	vector<int> water(v.size(), 0);
	int ans=0;

	maxL[0]=v[0];
	for(int i=1; i<v.size(); i++){
		maxL[i]=max(maxL[i-1], v[i]);
	}

	maxR[v.size()-1]=v[v.size()-1];
	for(int i=v.size()-2; i>=0; i--){
		maxR[i]=max(maxR[i+1], v[i]);
	}

	for(int i=0; i<v.size(); i++){
		water[i]=min(maxL[i], maxR[i])-v[i];
		ans += water[i];
	}

	return ans;
}


int main() {
	freopen("../input.txt", "r", stdin);  
    freopen("../output.txt", "w", stdout);

    freopen("../Error.txt", "w", stderr);
    
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};

    int ans = RainWaterTrapping(v);
    cout<<"Rain Water Trapping: "<<ans;
}