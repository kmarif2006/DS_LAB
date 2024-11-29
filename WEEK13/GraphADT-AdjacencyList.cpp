#include<bits/stdc++.h>
using namespace std;
class Graph{
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
  public:
  Node**adj;
  int vertices;
  public:
  Graph(int vert){
    vertices=vert;
    adj=new Node*[vertices];
    for(int i=0;i<vertices;i++){
      adj[i]=nullptr;
    }
  }
  public:
  void insert(int u,int v){
    if (u>=0&&u<vertices&&v>=0&&v<vertices)
    {
      Node* node1=new Node(v);
      node1->next=adj[u];
      adj[u]=node1;
      Node* node2=new Node(u);
      node2->next=adj[v];
      adj[v]=node2;
      cout<<"Vertices are inserted"<<endl;
    }
    else{
      cout<<"Invalid vertices"<<endl;
    }  
  }
  void delete_edge(int u,int v){
    if (u>=0&&u<vertices&&v>=0&&v<vertices)
    {
    Node* prev=nullptr;
    Node *current=adj[u];
    while(current!=nullptr&&current->data!=v){
      prev=current;
      current=current->next;
    }
    if(current==nullptr){
      cout<<"Edge doesn't exsits";
      return;
    }
    if(prev==nullptr){
      adj[u]=current->next;
      delete current;
    }else{
      prev->next=current->next;
      delete current;
    }
    prev=nullptr;
    current=adj[v];
    while(current!=nullptr&&current->data!=u){
      prev=current;
      current=current->next;
    }
    if(current==nullptr){
      cout<<"Edge doesn't exists"<<endl;
      return;
    }
    if(prev==nullptr){
      adj[v]=current->next;
      delete current;
    }else{
      prev->next=current->next;
      delete current;
    }
    cout<<"Edge is deleted"<<endl;
    }
    else{
      cout<<"Invalid vertices"<<endl;
    }
  }
  void display(){
    for(int i=0;i<vertices;i++){
      cout<<i<<":";
      Node* temp=adj[i];
      while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
      }
      cout<<"Null";
      cout<<"\n";
    }
  }
  void search(int u,int v){
    if (u>=0&&u<vertices&&v>=0&&v<vertices)
    {
      Node* current=adj[u];
      while(current!=nullptr){
        if(current->data==v){
          cout<<"Edge is found in the graph"<<endl;
          return;
        }
        current=current->next;
      }
      cout<<"Edge is not found"<<endl;
    }
    else{
      cout<<"vertices are invalid"<<endl;
    }
  }
};
int main(){
  int vertices;
  cout<<"Enter the number of vertices in the graph:";
  cin>>vertices;
  Graph gh(vertices);
  int choice,u,v;
  while(true){
    cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter Your Choice: ";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter the vertices(u,v) for an edge: ";
        cin>>u>>v;
        gh.insert(u,v);
        break;
      }
      case 2:{
        cout<<"Enter the vertices(u,v) to delete an edge: ";
        cin>>u>>v;
        gh.delete_edge(u,v);
        break;
      }
      case 3:{
        cout<<"Enter the vertices (u,v) to search an edge: ";
        cin>>u>>v;
        gh.search(u,v);
        break;
      }
      case 4:{
        gh.display();
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
