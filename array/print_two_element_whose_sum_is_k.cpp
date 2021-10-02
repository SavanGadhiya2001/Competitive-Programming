#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC : O(n^2)
void PrintElement1(int arr[], int n, int target){
	int i,j;

	for(i=0; i<n; i++){
		int sm;
		for(j=i+1; j<n; j++){
			sm = arr[i]+arr[j];

			if(sm == target){
				cout<<arr[i]<<" "<<arr[j]<<endl;
				return;
			}
		}
	}
	cout<<"Element Not Found ...\n";
}

// TC : O(n * log(n))
void PrintElement2(int arr[], int n, int target){
	sort(arr, arr+n);

	for(int i=0; i<n; i++){
		int req = target - arr[i];

		if(binary_search(arr, arr+n, req)){
			cout<<arr[i]<<" "<<req<<endl;
			return;
		}
	}
}

// TC : O(n)
void PrintElement3(int arr[], int n, int target){
	unordered_set<int> us;	// unordered_set takes O(n) for finding element

	for(int i=0; i<n; i++){
		int req = target - arr[i];

		// auto fd = find(us.begin(), us.end(), req);
//   ---> OR <---	
		auto fd = us.find(req);
		
		if(fd!=us.end()){
			cout<<arr[i]<<" "<<req<<endl;
			return;
		}

		us.insert(arr[i]);
	}
}

int main(){
	int arr[] = {10,5,2,3,-6,9,11};
	int target = 4;

	int n = sizeof(arr)/sizeof(arr[0]);

	// Method : 1
	PrintElement1(arr, n, target);

	// Method : 2
	PrintElement2(arr, n, target);

	// Method : 3
	PrintElement3(arr, n, target);
}