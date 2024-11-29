#include<bits/stdc++.h>
using namespace std;
class Stack{
  class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int value){
      data=value;
      next=nullptr;
    }
  };
  public:
  Node* top;
  int size;
  public:
  Stack(){
    top=nullptr;
    size=0;
  }
  public:
  void push(int value){
    Node* node=new Node(value);
    size++;
    if(top==nullptr){
      top=node;
      return;
    }
    node->next=top;
    top=node;
    
  }
  int pop(){
    
    if(top==nullptr){
      cout<<"Stack is empty\n";
      return -1;
    }
    int val=top->data;
    Node* deleteNode=top;
    top=top->next;
    delete deleteNode;
    size--;
    return val;
  }
  int peek(){
    if(top==nullptr){
      cout<<"Stack is empty\n";
      return -1;
    }
    return top->data;
  }
};
int main(){
  Stack stack;
  int choice,value;
  while(true){
    cout<<"\n1.Push\n2.Pop\n3.Peek\n4.Exit\nEnter Your Choice: ";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter value to push: ";
        cin>>value;
        stack.push(value);
        break;
      }
      case 2:{
        cout<<stack.pop();
        break;
      }
      case 3:{
        cout<<stack.peek();
        break;

      }
      case 4:{
        cout<<"Exiting...\n";
        return 0;
      }
    }
  }
}