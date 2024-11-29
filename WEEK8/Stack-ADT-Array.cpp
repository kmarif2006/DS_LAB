#include<bits/stdc++.h>
using namespace std;
class Stack{
  public:
  int *arr;
  int size;
  int top;
  int capacity;
  public:
  Stack(int cap){
    capacity=cap;
    arr=new int[capacity];
    size=0;
    top=-1;
  }
  public:
  void push(int value){
    if(size==capacity){
      cout<<"Stack is full";
      return;
    }
    top+=1;
    arr[top]=value;
    size++;
  }
  int pop(){
    if(size==0){
      cout<<"Stack is empty";
      return -1;
    }
    int val=arr[top];
    if(top==0){
      top=-1;
      return val;
    }
    top-=1;
    size--;
    return val;
  }
  int peek(){
    if(size==0){
      cout<<"Stack is Empty";
      return -1;
    }
    return arr[top];
  }
  
};
int main(){
  
  int capacity;
  cout<<"Enter the capacity of the stack: ";
  cin>>capacity;
  Stack stack(capacity);
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
        cout<<"Exiting...";
        return 0;
      }
    }
  }
}