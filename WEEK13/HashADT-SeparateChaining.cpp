#include<bits/stdc++.h>
using namespace std;
class HashTable{
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
  Node **table;
  int capacity;
  public:
  HashTable(int cap){
    capacity=cap;
    table=new Node*[capacity];
    for(int i=0;i<capacity;i++){
      table[i]=nullptr;
    }
  }
  int hashFunction(int key){
    return key%capacity;
  }
  public:
  void insert(int value){
    int index=hashFunction(value);
    Node* node=new Node(value);
    node->next=table[index];
    table[index]=node;
  }
  void delete_key(int value){
    int index=hashFunction(value);
    Node* prev=nullptr;
    Node* current=table[index];
    while(current!=nullptr&&current->data!=value){
      prev=current;
      current=current->next;
    }
    if(current!=nullptr){
      if(prev==nullptr){
        table[index]=current->next;
        delete current;
      }
      else{
        prev->next=current->next;
      delete current;
      }
      cout<<value<<" is deleted."<<endl;
    }
    else{
      cout<<value<<" is not found."<<endl;
    }
  }
  bool search(int key){
    int index=hashFunction(key);
    Node* current=table[index];
    while(current!=nullptr){
      if(current->data==key){
        cout<<key<<" is present at index "<<index;
        return true;
      }
      current=current->next;
    }
    cout<<key<<" is not found in the Hash Table."<<endl;
    return false;
  }
};
int main(){
  int capacity;
  cout<<"Enter the capacity of the HashTable: ";
  cin>>capacity;
  HashTable map(capacity);
  int choice,value,key;
  while(true){
    cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Exit\nEnter Your Choice:";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter value to insert: ";
        cin>>value;
        map.insert(value);
        break;
      }
      case 2:{
        cout<<"Enter value to delete: ";
        cin>>value;
        map.delete_key(value);
        break;
      }
      case 3:{
        cout<<"Enter the key to search for: ";
        cin>>key;
        map.search(key);
        break;
      }
      case 4:{
        cout<<"Exiting...";
        return 0;
      }
      default:{
        cout<<"Invalid Choice..";
        break;
      }
    }

  }
}