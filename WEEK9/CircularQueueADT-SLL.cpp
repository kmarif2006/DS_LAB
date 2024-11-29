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
  int capacity;
  int size;
  public:
  Queue(int cap){
    capacity=cap;
    size=0;
    front=nullptr;
    rear=nullptr;
  }
  public:
  void enqueue(int value){
    if(size==capacity){
      cout<<"Queue is full";
      return;
    }
    Node* node=new Node(value);
    size++;
    if(rear==nullptr){
      front=node;
      rear=node;
      rear->next=front;
      return;
    }
    
    rear->next=node;
    rear=node;
    rear->next=front;
  }
  int dequeue(){
    if(front==nullptr){
      return -1;
    }
    int val=front->data;
    if(front==rear){
      delete front;
      size--;
      front=nullptr;
      rear=nullptr;
      return val;
    }
    Node* deleteNode=front;
    front=front->next;
    rear->next=front;
    delete deleteNode;
    size--;
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
  int capacity;
  cout<<"Enter the capacity of the queue: ";
  cin>>capacity;
  Queue queue(capacity);
  int choice,value;
  while(true){
    cout<<"\n1.Enqueue\n2.Dequeue\n3.peek\n4.Exit\nEnter Your Choice: ";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter value to insert: ";
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
        cout<<"Enter valid choice.";
        break;
      }
    }
  }
}