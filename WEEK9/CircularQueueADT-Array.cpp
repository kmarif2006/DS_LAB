#include<bits/stdc++.h>
using namespace std;
class Queue{
public:
int *arr;
int size;
int front;
int rear;
int capacity;
public:
Queue(int cap){
capacity=cap;
arr=new int[capacity];
size=0;
front=-1;
rear=-1;
}
public:
void enqueue(int value){
  if(size==capacity){
    cout<<"Queue is full\n";
    return;
  }
  if(rear==-1){
    front=0;
    rear=0;
    arr[rear]=value;
    size++;
    return;
  }
  rear=(rear+1)%capacity;
  arr[rear]=value;
  size++;
}
int dequeue(){
  if(size==0){
    cout<<"Queue is empty\n";
    return -1;
  }
  int val=arr[front];
  front=(front+1)%capacity;
  size--;
  if(size==0){
    front=-1;
    rear=-1;
  }
  return val;
}
int peek(){
  if(size==0){
    cout<<"Queue is empty\n";
    return -1;
  }
return arr[front];
}
};

int main(){
  int capacity;
  cout<<"Enter the capacity of queue: ";
  cin>>capacity;
  Queue queue(capacity);
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
        cout<<"Enter a valid option..";
        break;
      }
    }
  }
}