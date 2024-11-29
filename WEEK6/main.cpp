#include<bits/stdc++.h>
#include "Round_robin_sch.h"
using namespace std;

int main(){
  int timeSlice,choice,processTime;
  cout<<"Enter the fixed time slice for each process: ";
  cin>>timeSlice;
  round_robin_algo scheduler(timeSlice);
  while(true){
    cout<<"\n1.Insert Process\n2.Execute\n3.Exit\nEnter Your Choice: ";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"Enter the process time required: ";
        cin>>processTime;
        scheduler.insertProcess(processTime);
        break;
      }
      case 2:{
        scheduler.Execute();
        break;
      }
      case 3:{
        cout<<"Exiting...";
        return 0;
      }
      default:{
        cout<<"Invalid choice.";
        break;
      }
    }
  }
}