#ifndef ROUND_ROBIN_SCH_H
#define ROUND_ROBIN_SCH_H
#include<bits/stdc++.h>
using namespace std;
class round_robin_algo{
  class Node{
  public:
  int time;
  Node* next;
  public:
  Node(int t){
    time=t;
    next=nullptr;
  }
};
public:
Node* head;
Node* tail;
int scheduling_time;
public:
round_robin_algo(int time){
  head=nullptr;
  tail=nullptr;
  scheduling_time=time;
}
public:
void insertProcess(int time){
  Node* node=new Node(time);
  if(head==nullptr){
    head=node;
    tail=node;
    tail->next=head;
    return;
  }else{
    tail->next=node;
    node->next=head;
    tail=node;
  } 
}
void Execute(){
  if(head==nullptr){
    cout<<"No processes to execute"<<endl;
    return;
  }
  
  head->time-=scheduling_time;
  if(head->time<=0){
    cout<<"Process completed"<<endl;
    if(head==tail){
      delete head;
      head=tail=nullptr;
    }else{
      Node* temp=head;;
      head=head->next;
      tail->next=head;
      delete temp;
    }
   
  }else{
    tail=head;
    head=head->next;
  }
}
};
#endif