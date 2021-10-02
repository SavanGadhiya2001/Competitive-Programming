#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool HasHigherPress(char c1, char c2) {
    //if((c1=='*'||c1=='/') && (c2=='+'||c2=='-'))    return true;
    //else if(((c1=='+'||c1=='-') && (c2=='+'||c2=='-'))||((c1=='*'||c1=='/') && (c2=='*'||c2=='/')))   return true;
    //return false;

    // ------- OR ---------

    if((c1=='+'||c1=='-')&&(c2=='*'||c2=='/'))  return false;
    return true;
}

string InfixToPostfix(string str) {
    stack<char> s;
    string res = "";
    for(int i=0; i<str.size(); i++) {
        if(str[i]>=65 && str[i]<=90){
            res = res+str[i];
        }
        else{
            while(!s.empty() && HasHigherPress(s.top(), str[i])){
                res=res+s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()) {
        res = res+s.top();
        s.pop();
    }
    return res;
}

int main() {
    string infix = "A+B*C-D*E";
    string postfix = InfixToPostfix(infix);
    cout<<"ans: "<<postfix;
}
