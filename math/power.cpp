#include<iostream>
using namespace std;

int powerRecursive(int n, int p){
	if(p==0)
		return 1;
	int a = powerRecursive(n, p/2);
	if(p%2==0){
		return a*a;
	}
	else{
		return n*a*a;
	}
}

int powerIterative(int n, int p){
	int ans=1;
	while(p>0){
		if(p%2==1)
			ans=ans*n;
		n=n*n;
		p=p/2;
	}
	return ans;
}

int main(){
	freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	cout<<"powerRecursive: "<<powerRecursive(3, 47)<<endl;
	cout<<"powerIterative: "<<powerIterative(3, 47)<<endl;
}