#include<bits/stdc++.h>
using namespace std;
class List{
  class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int value){
      data=value;
      next=nullptr;
      prev=nullptr;
    }
  };
  public:
  Node* head;
  int size;
  public:
  List(){
    head=nullptr;
    size=0;
  }
  public:
  Node* insertBegin(Node* head,int value){
    Node* node=new Node(value);
    size++;
    if(head==nullptr){
      head=node;
      return head;
    }
    node->next=head;
    head->prev=node;
    head=node;
    return node;
  }
  Node* insertEnd(Node* head,int value){
    Node* node=new Node(value);
    size++;
    if(head==nullptr){
      head=node;
      return head;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
      temp=temp->next;
    }
    temp->next=node;
    node->prev=temp;
    return head;
  }
  Node* insertPosition(Node* head,int value,int position){
    if(position<0||position>size){
      cout<<"Invalid Position\n";
      return head;
    }
    if(position==0){
      return insertBegin(head,value);
    }
    if(position==size){
      return insertEnd(head,value);
    }
    Node* node=new Node(value);
    size++;
    if(head==nullptr){
      head=node;
      return head;
    }
    Node* temp=head;
    for(int i=1;i<position;i++){
      temp=temp->next;
    }
    Node* nextNode=temp->next;
    node->next=nextNode;
    nextNode->prev=node;
    temp->next=node;
    node->prev=temp;
    return head;
  }
  Node* deleteBegin(Node* head){
    if(head==nullptr){
      cout<<"List is empty\n";
      return nullptr;
    }
    if(head->next==nullptr){
      delete head;
      size--;
      return nullptr;
    }
    Node* deleteNode=head;
    head=head->next;
    head->prev=nullptr;
    delete deleteNode;
    size--;
    return head;
  }
  Node* deleteEnd(Node* head){
    if(head==nullptr){
      cout<<"List is empty\n";
      return nullptr;
    }
    if(head->next==nullptr){
      delete head;
      size--;
      return nullptr;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
      temp=temp->next;
    }
    Node* deleteNode=temp->next;
    temp->next=nullptr;
    delete deleteNode;
    size--;
    return head;

  }
  Node* deletePosition(Node* head,int position){
    if(head==nullptr){
      cout<<"List is empty\n";
      return nullptr;
    }
    if(position<0||position>=size){
      cout<<"Invalid Position";
      return head;
    }
    if(position==0){
      return deleteBegin(head);
    }
    if(position==size-1){
      return deleteEnd(head);
    }
    Node* temp=head;
    for(int i=1;i<position;i++){
      temp=temp->next;
    }
    Node* deleteNode=temp->next;
    temp->next=temp->next->next;
    if(temp->next!=nullptr){
        temp->next->prev=temp;
    }
    delete deleteNode;
    size--;
    return head;
  }
  void display(Node* head){
    if(head==nullptr){
      cout<<"List is empty\n";
      return;
    }
    Node* temp=head;
    while(temp!=nullptr){
      cout<<temp->data<<" ";
      temp=temp->next;
    }
  }
  void search(Node* head,int key){
    if(head==nullptr){
      cout<<"List is empty\n";
      return;
    }
    Node* temp=head;
    int index=0;
    while(temp!=nullptr){
      if(temp->data==key){
        cout<<"Element is found at index "<<index<<"\n";
        return;
      }
      index++;
      temp=temp->next;
      
    }
    cout<<"Element is not found";
  }
};
int main(){
  List list;
  int choice,value,position,key;
  while(true){
    cout<<"\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Exit\nEnter your choice: ";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter value to enter: ";
        cin>>value;
        list.head=list.insertBegin(list.head,value);
        break;
      }
      case 2:{
        cout<<"Enter value to enter: ";
        cin>>value;
        list.head=list.insertEnd(list.head,value);
        break;
      }
      case 3:{
        cout<<"Enter value to enter: ";
        cin>>value;
        cout<<"Enter position to insert: ";
        cin>>position;
        list.head=list.insertPosition(list.head,value,position);
        break;
      }
      case 4:{
        list.head=list.deleteBegin(list.head);
        break;
      }
      case 5:{
        list.head=list.deleteEnd(list.head);
        break;
      }
      case 6:{
        cout<<"Enter position to delete: ";
        cin>>position;
        list.head=list.deletePosition(list.head,position);
        break;
      }
      case 7:{
        cout<<"Enter the value to search for: ";
        cin>>key;
        list.search(list.head,key);
        break;
      }
      case 8:{
        list.display(list.head);
        break;
      }
      case 9:{
        cout<<"Exiting...";
        return 0;
      }
      default:{
        cout<<"Invalid option.\n";
        break;
      }
    }
  }
}