#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H
#include<bits/stdc++.h>
using namespace std;
class webbrowser{
  class Node{
    public:
    int webdata;
    Node* next;
    Node* prev;
    public:
    Node(int data){
      webdata=data;
      next=nullptr;
      prev=nullptr;
    }
  };
  Node* head;
  Node* curr;
  public:
  webbrowser(){
    head=nullptr;
    curr=nullptr;
  }
  public:
  void new_webpage(int value){
    Node* node=new Node(value);
    if(head==nullptr){
      head=node;
      curr=node;
      return;
    }
    Node* temp=curr->next;
    while(temp!=nullptr){
      Node* deleteNode=temp;
      temp=temp->next;
      delete deleteNode; 
    }
    node->prev=curr;
    curr->next=node;
    curr=node;
  }
  void front(){
    if(curr!=nullptr&&curr->next!=nullptr){
      curr=curr->next;
    }
    else{
      cout<<"No forward page available."<<endl;
    }
  }
  void back(){
    if(curr!=nullptr&&curr->prev!=nullptr){
      curr=curr->prev;
    }else{
      cout<<"No backward page available."<<endl;
    }
  }
  void displayCurrent(){
    if(curr!=nullptr){
      cout<<"Current Webpage: "<<curr->webdata<<endl;
    }else{
      cout<<"No Webpage Open."<<endl;
    }
  }
};

#endif