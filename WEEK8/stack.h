#ifndef STACK_H
#define STACK_H
#include<bits/stdc++.h>
using namespace std;
class Stack{
  class Node{
    public:
    char data;
    Node* next;
    public:
    Node(char value){
      data=value;
      next=nullptr;
    }
  };
  public:
  Node* top;
  public:
  Stack(){
    top=nullptr;
  }
  public:
  void push(char value){
    Node* node=new Node(value);
    if(top==nullptr){
      top=node;
      return;
    }
    node->next=top;
    top=node;
  }
  char pop(){
    if(top==nullptr){
      return '\0';
    }
    char val=top->data;
    top=top->next;
    return val;
  }
  char peek(){
    if(top==nullptr){
      return '\0';
    }
    return top->data;
  }
  bool empty(){
    if(top==nullptr){
      return true;
    }
    return false;
  }
};
#endif