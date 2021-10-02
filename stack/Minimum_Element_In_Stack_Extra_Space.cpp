// https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

stack<int> s;	// stack
stack<int> ss;	// suporting stack

void Push(int x) {
	s.push(x);
	if(ss.empty() || x <= ss.top())
		ss.push(x);
	return;
}

int Pop() {
	if(s.empty())
		return -1;
	int ans = s.top();
	s.pop();

	if(ans==ss.top())
		ss.pop();
	return 2;
}

int getMin() {
	if(ss.empty())
		return -1;
	return ss.top();
}

int main() {
	// freopen("../input.txt", "r", stdin);  
    // freopen("../output.txt", "w", stdout);
    
    Push(2);
    Push(4);
    Push(6);
    cout<<Pop()<<endl;
    cout<<getMin();
}