#include<iostream>
using namespace std;

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int x) {
    if(top == MAX_SIZE-1) {
        cout<<"Error: Stack Overflow\n";
        return;
    }
    A[++top] = x;
}

void Pop() {
    if(top == -1) {
        cout<<"Error: No Element to pop\n";
        return;
    }
    top--;
}

int Top() {
    return A[top];
}

// Only for testing
void Print() {
    int i;
    cout<<"Stack: ";
    for(i=0; i<=top; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int main() {
    Push(2); Print();
    Push(5); Print();
    Push(12); Print();
    Pop(); Print();
    Push(22); Print();
}
