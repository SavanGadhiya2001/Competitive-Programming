#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head;

Node *createNode(){
    Node *temp = new Node();
    temp->next = NULL;
    return temp;
}

void Insert(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Reverse() {
    if(head == NULL)
        return;
    stack <struct Node *> S;
    Node *temp = head;

    while(temp != NULL) {
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while(!S.empty()) {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void Print() {
    struct Node *temp = head;
    cout<<"List is : ";
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Insert(2); Print();
    Insert(12); Print();
    Insert(22); Print();
    Insert(32); Print();
    Reverse();
    Insert(42); Print();
}
