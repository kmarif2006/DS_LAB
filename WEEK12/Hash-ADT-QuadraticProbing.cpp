#include<bits/stdc++.h>
using namespace std;
class HashTable{
  private:
  int *arr;
  int capacity;
  int size;
  public:
  HashTable(int cap){
    capacity=cap;
    arr=new int[capacity];
    size=0;
    for(int i=0;i<capacity;i++){
      arr[i]=-1;
    }
  }
  public:
  int hashFunction(int key){
    return key%capacity;
  }
  public:
  void insert(int value){
    int index=hashFunction(value);
    int i=0;
    while(arr[(index+i*i)%capacity]!=-1&&i<capacity){
      i++;
    }
    int newIndex=(index+i*i)%capacity;
    if(i<capacity){
      arr[newIndex]=value;
      size++;
    }
    else{
      cout<<"Hash Table is full...";
    }
  }
  void deleteKey(int value){
    int index=hashFunction(value);
    int i=0;
    while(arr[(index+i*i)%capacity]!=-1&&arr[(index+i*i)%capacity]!=value&&i<capacity){
      i++;
    }
    int deleteIndex=(index+i*i)%capacity;
    if(arr[deleteIndex]==value){
      arr[deleteIndex]=-1;
      size--;
    }
    else{
      cout<<"Key is not found in HashTable";
    }
  }
  bool search(int key){
    int index=hashFunction(key);
    int i=0;
    while(arr[(index+i*i)%capacity]!=-1&&arr[(index+i*i)%capacity]!=key&&i<capacity){
      i++;
    }
    int searchIndex=(index+i*i)%capacity;
    if(arr[searchIndex]==key){
      cout<<"Key found at index."<<searchIndex;
      return true;
    }
    else{
      cout<<"Key not found in the HashTable.";
      return false;
    }
  }
  void display(){
    for(int i=0;i<capacity;i++){
      if(arr[i]==-1){
        cout<<"_"<<" ";
      }
      else{
        cout<<arr[i]<<" ";
      }
    }
  }

};
int main(){
  int capacity;
  cout<<"Enter the capacity of the HashTable: ";
  cin>>capacity;
  HashTable map(capacity);
  int choice,value,key;
  while(true){
    cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter Your Choice: ";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter the key to insert: ";
        cin>>value;
        map.insert(value);
        break;
      }
      case 2:{
        cout<<"Enter the key to delete: ";
        cin>>value;
        map.deleteKey(value);
        break;
      }
      case 3:{
        cout<<"Enter key to search: ";
        cin>>value;
        map.search(value);
        break;
      }
      case 4:{
        map.display();
        break;
      }
      case 5:{
        cout<<"Exiting...";
        return 0;
      }
      default:{
        cout<<"Invalid choice..";
        break;
      }
    }
  }
}
