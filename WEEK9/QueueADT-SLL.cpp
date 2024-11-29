#include<bits/stdc++.h>
using namespace std;
class Queue{
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
  Node* front;
  Node* rear;
  int size;
  public:
  Queue(){
    front=nullptr;
    rear=nullptr;
    size=0;
  }
  public:
  void enqueue(int value){
    Node *node=new Node(value);
    size++;
    if(rear==nullptr){
      front=node;
      rear=node;
      return;
    }
    rear->next=node;
    rear=node;
  }
  int dequeue(){
    if(front==nullptr){
      return -1;
    }
    int val=front->data;
    if(front==rear){
      delete front;
      front=nullptr;
      rear=nullptr;
      return val;
    }
    Node* deleteNode=front;
    front=front->next;
    delete deleteNode;
    return val;
  }
  int peek(){
    if(front==nullptr){
      return -1;
    }
    return front->data;
  }
};
int main(){

  Queue queue;
  int choice,value;
  while(true){
    cout<<"\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\nEnter Your Choice: ";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter value: ";
        cin>>value;
        queue.enqueue(value);
        break;
      }
      case 2:{
        cout<<queue.dequeue();
        break;
      }
      case 3:{
        cout<<queue.peek();
        break;
      }
      case 4:{
        cout<<"Exiting...";
        return 0;
      }
      default:{
        cout<<"Invalid Choice.";
        break;
      }
    }
  }
}