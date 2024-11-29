#include<bits/stdc++.h>
using namespace std;
class HashTable{
public:
int *mpp;
int capacity;
int size;
public:
HashTable(int cap){
  capacity=cap;
  mpp=new int[capacity];
  size=0;
  for(int i=0;i<capacity;i++){
    mpp[i]=-1;
  }
}
public:
int HashFunction(int key){
  return key%capacity;
}
void insert(int value){
  if(size==capacity){
    cout<<"HashTable is full";
    return;
  }
int index=HashFunction(value);
while(mpp[index]!=-1){
  index=(index+1)%capacity;
}
mpp[index]=value;
size++;
}
void delete_value(int value){
  int index=HashFunction(value);
  int originalIndex=index;
  while(mpp[index]!=-1){
    if(mpp[index]==value){
      mpp[index]=-1;
      size--;
      return;
    }
    index=(index+1)%capacity;
    if(index==originalIndex){
      break;
    }
  }
  cout<<"Element is not found in HashTable";
}
int search(int value){
int index=HashFunction(value);
int originalIndex=index;
while(mpp[index]!=-1){
  if(mpp[index]==value){
    cout<<"Element found at index :"<<index;
    return 1;
  }
  index=(index+1)%capacity;
  if(index==originalIndex){
    break;
  }
}
cout<<"Element is not found.";
return 0;
}
void display(){
  for(int i=0;i<capacity;i++){
    if(mpp[i]==-1){
      cout<<"_"<<" ";
    }
    else{
      cout<<mpp[i]<<" ";
    }
  }
}
};
int main(){
  int capacity;
  cout<<"Enter the capacity of Hashmap: ";
  cin>>capacity;
  HashTable map(capacity);
  int choice,value,key;
  while(true){
    cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter Your Choice: ";
    cin>>choice;
    switch(choice){
      case 1:{
      cout<<"Enter value to insert in HashTable: ";
      cin>>value;
      map.insert(value);
      break;
    }
    case 2:{
      cout<<"Enter value to delete in HashTable: ";
      cin>>value;
      map.delete_value(value);
      break;
    }
    case 3:{
      cout<<"Enter value to serch for: ";
      cin>>key;
      map.search(key);
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
      cout<<"Invalid Choice";
      break;
    }
    }
    
  }
}