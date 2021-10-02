// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int minEle;

int getMin() {
	if(s.size() == 0)
		return -1;
	return minEle;
}

void push(int x) {
	if(s.size() == 0){
		s.push(x);
		minEle = x;
	}
	else {
		if(x >= minEle){
			s.push(x);
		}
		else if(x<minEle){
			s.push(2*x - minEle);
			minEle = x;
		}
	}
}

void pop() {
	if(s.size() == 0)
		return;
	if(s.top()>=minEle){
		s.pop();
	}
	else if(s.top()<minEle){
		minEle=2*minEle-s.top();
		s.pop();
	}
}

int top() {
	if(s.size() == 0)
		return -1;
	if(s.top() >= minEle){
		return s.top();
	}
	else if(s.top()<minEle){
		return minEle;
	}
}

int main() {
	push(12);
	cout<<top()<<endl;
	cout<<"minEle: "<<getMin()<<endl;
	push(2);
	cout<<top()<<endl;
	cout<<"minEle: "<<getMin()<<endl;
	push(5);
	cout<<top()<<endl;
	cout<<"minEle: "<<getMin()<<endl;
}