#include<bits/stdc++.h>
using namespace std;
class PQ{
  private:
  vector<int>heap;
  private:
  void heapify_up(int index){
    if(index==0){
      return;
    }
    int parent=(index-1)/2;
    if(heap[index]>heap[parent]){
      swap(heap[index],heap[parent]);
      heapify_up(parent);
    }
  }
  void heapify_down(int index){
    
    int largest=index;
    int left_child=2*index+1;
    int right_child=2*index+2;
    if(left_child<heap.size()&&heap[largest]<heap[left_child]){
      largest=left_child;
    }
    if(right_child<heap.size()&&heap[largest]<heap[right_child]){
      largest=right_child;
    }
    if(largest!=index){
      swap(heap[largest],heap[index]);
      heapify_down(largest);
    }
  }
  public:
  void insert(int value){
    heap.push_back(value);
    heapify_up(heap.size()-1);
  }
  void delete_heap(){
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    heapify_down(0);
  }
  void display(){
    for(int val:heap){
      cout<<val<<" ";
    }
    cout<<endl;
  }
  int search(int key){
    for(int i=0;i<heap.size();i++){
      if(heap[i]==key){
        cout<<"Element found in the heap."<<endl;
        return 1;
      }
    }
    cout<<"Element not found in the heap."<<endl;
    return 0;
  }
  void heap_sort(){
    vector<int> tempHeap=heap;
    for(int i=heap.size()-1;i>0;i--){
      swap(heap[0],heap[i]);
      heap.resize(i);
      heapify_down(0);
    }
    cout<<"Sorted Elements: ";
    for(int val:heap){
      cout<<val<<" ";
    }
    cout<<endl;
    heap=tempHeap;
  }
};
int main(){
  PQ queue;
  int choice,value,key;
  while(true){
    cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Sort (Heap Sort)\n6.Exit\nEnter Your Choice: ";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter value to insert: ";
        cin>>value;
        queue.insert(value);
        break;
      }
      case 2:{
        queue.delete_heap();
        break;
      }
      case 3:{
        queue.display();
        break;
      }
      case 4:{
        cout<<"Enter element to search: ";
        cin>>key;
        queue.search(key);
        break;
      }
      case 5:{
        queue.heap_sort();
        break;
      }
      case 6:{
        cout<<"Exiting...";
        return 0;
      }
      
    }
  }
}