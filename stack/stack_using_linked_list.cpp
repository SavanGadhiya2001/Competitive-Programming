#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *link;
};

struct Node *top = NULL;

void Push(int x) {
    struct Node *temp = new Node;

    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop() {
    struct Node *temp;
    if(top == NULL)
        return;
    temp = top;
    top = top->link;
    free(temp);
}

void Print() {
    struct Node *temp = top;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}

int main() {
    top = NULL;
    Push(2); Print();
    Push(4); Print();
    Pop(); Print();
    Push(8); Print();
    Push(10); Print();
}
