// this will work only in 0 to 9; so u can't enter 32 ...

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Evaluate(int op1, int op2, char op) {
    if(op=='+') return op1+op2;
    else if(op=='-')    return op1-op2;
    else if(op=='*')    return op1*op2;
    else    return op1/op2;
}

int EvaluatePostfix(string str) {
    stack<int> s;
    for(int i=0; i<str.size(); i++){
        if(str[i]>=48 && str[i]<=57){
            s.push(str[i]-48);
        }
        else{
            int op2 = s.top();
            s.pop();
            if(s.empty()){
                cout<<"Invalid Expression\n";
                return -1;
            }
            int op1 = s.top();
            s.pop();
            int a = Evaluate(op1, op2, str[i]);
            s.push(a);
        }
    }
    int ans = s.top();
    s.pop();
    if(s.empty())   return ans;
    else {
        cout<<"Invalid Expression\n";
        return -1;
    }
}

int main() {
    string s = "23*54*+9+-";
    int ans = EvaluatePostfix(s);
    cout<<"ans:"<<ans;
}
