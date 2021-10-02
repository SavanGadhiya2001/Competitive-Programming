#include<iostream>
#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define countdigit(x) floor(log10(x)+1)
#define all(x) x.begin(), x.end()
#define asort(v) sort(v.begin(), v.end());  ///sorting in ascending order
#define dsort(v) sort(v.begin(), v.end(), greater<int>());  ///sorting in descending order
#define uq(x) x.resize(distance(x.begin(), unique(x.begin(), x.end())))
#define ll long long
#define PI 3.1415926535
#define ff first
#define ss second
#define pb push_back
#define ee "\n"
using namespace std;


void solve()
{
	int a,b;	
	// cout<<"Enter numbers: ";
	cin>>a>>b;
	cout<<a<<" "<<b<<endl;
	return;
}


int main() {
	IOS;

    freopen("../input.txt", "r", stdin);  
    freopen("../output.txt", "w", stdout);

	ll test;	cin >> test;
	while (test--)
		solve();
}