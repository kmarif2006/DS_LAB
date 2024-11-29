#include<bits/stdc++.h>
using namespace std;
class Graph{
  int **adj;
  int vertices;
  public:
  Graph(int ver){
    vertices=ver;
    adj=new int*[vertices];
    for(int i=0;i<vertices;i++){
      adj[i]=new int[vertices];
      for(int j=0;j<vertices;j++){
        adj[i][j]=0;
      }
    }
  }
  ~Graph(){
    for(int i=0;i<vertices;i++){
      delete[]adj[i];
    }
    delete[] adj;
  }
  public:
  void insert(int u,int v){
    if (u<vertices&&u>=0&&v>=0&&v<vertices)
    {
      adj[u][v]=1;
      adj[v][u]=1;
      cout<<"Edge Inserted"<<endl;
    }else{
      cout<<"Invalid vertices!"<<endl;
    }  
  }
  void deleteEdge(int u,int v){
    if (u<vertices&&u>=0&&v>=0&&v<vertices)
    {
      if(adj[u][v]==1){
        adj[u][v]=0;
        adj[v][u]=0;
        cout<<"Edge Deleted"<<endl;
      }
      else{
        cout<<"Edge doesn't exists"<<endl;
      }
    }
    else{
      cout<<"Invalid vertices!"<<endl;
    } 
  }
  void search(int u,int v){
    if(u>=0&&u<vertices&&v>=0&&v<vertices)
    {
      if (adj[u][v]==1 &&adj[v][u]==1)
      {
        cout<<"Edge exists"<<endl;
      }
      else{
        cout<<"Edge doesn't exists";
      }
    }
    else{
      cout<<"Invalid Vertices!"<<endl;
    }
    
  }
  void display(){
    cout<<"Adjacency Matrix:"<<endl;
    for(int i=0;i<vertices;i++){
      for(int j=0;j<vertices;j++){
        cout<<adj[i][j]<<" ";
      }
      cout<<endl;
    }
  }
};
int main(){
  int u,v,choice,vertices;
  cout<<"Enter the no of vertices in the graph: ";
  cin>>vertices;
  Graph gh(vertices);
  while(true){
    cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter Your Choice: ";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter the vertices(u,v) to insert an edge: ";
        cin>>u>>v;
        gh.insert(u,v);
        break;
      }
      case 2:{
        cout<<"Enter the vertices(u,v) to delete an edge: ";
        cin>>u>>v;
        gh.deleteEdge(u,v);
        break;
      }
      case 3:{
        cout<<"Enter the vertices(u,v) to search for an edge: ";
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
        cout<<"Invalid choice";
        break;
      }
    }
  }
}