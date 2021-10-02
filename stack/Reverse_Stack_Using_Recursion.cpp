#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack<int> &s, int val){
    if(s.size()==0){
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();

    InsertAtBottom(s, val);

    s.push(temp);
}

void ReverseStack(stack<int> &s){
    if(s.size()==1){
        return;
    }

    int val = s.top();
    s.pop();

    ReverseStack(s);

    InsertAtBottom(s, val);
}


int main() {
	// freopen("../input.txt", "r", stdin);  
    // freopen("../output.txt", "w", stdout);
    
    stack<int> s;

    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);

    ReverseStack(s);

    int sz = s.size();
    for(int i=0; i<sz; i++){
        cout<<s.top()<<" ";
        s.pop();
    }
}