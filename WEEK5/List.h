#ifndef LIST_H
#define LIST_H
#include<bits/stdc++.h>
using namespace std;
class List{
  class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int value){
      data=value;
      next=nullptr;
    }
  } ;
  private:
  Node* head;
  public:
  List(){
    head=nullptr;
  }
  public:
  Node* getHead(){
    return head;
  }
  void insertAscending(int value){
    Node* node=new Node(value);
    if(head==nullptr||head->data>value){
      node->next=head;
      head=node;
      return;
    }else{
      Node* temp=head;
      Node* prev=nullptr;
      while(temp!=nullptr&&temp->data<value){
        prev=temp;
        temp=temp->next;
      }
      if(temp==nullptr){
        prev->next=node;
        return;
      }
      prev->next=node;
      node->next=temp;
    }
  }
  void display(){
    Node* temp=head;
    while(temp!=nullptr){
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    cout<<endl;
  }
  List merge(List l1,List l2){
    List mergedList;
    Node* ptr1=l1.head;
    Node* ptr2=l2.head;
    while(ptr1!=nullptr&&ptr2!=nullptr){
      if(ptr1->data<=ptr2->data){
        mergedList.insertAscending(ptr1->data);
        ptr1=ptr1->next;
      }else{
        mergedList.insertAscending(ptr2->data);
        ptr2=ptr2->next;
      }
    }
    while(ptr1!=nullptr){
      mergedList.insertAscending(ptr1->data);
      ptr1=ptr1->next;
    }
    while(ptr2!=nullptr){
      mergedList.insertAscending(ptr2->data);
      ptr2=ptr2->next;
    }
    return mergedList;
  }
};
#endif 