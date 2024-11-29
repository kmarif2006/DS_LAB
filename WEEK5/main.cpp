#include<bits/stdc++.h>
#include"List.h"
using namespace std;
int main(){
  List l1,l2,l3;
  int choice,value;
  while(true){
    cout<<"\n1.Insert into List 1\n2.Insert into List 2\n3.Merge List 1 and List 2 into List 3\n4.Display List\n5.Exit\nEnter Your Choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
      cout<<"Enter value to insert in List 1: ";
      cin>>value;
      l1.insertAscending(value);
      break;
    case 2:
      cout<<"Enter value to insert in List 2: ";
      cin>>value;
      l2.insertAscending(value);
      break;
    case 3:
      l3=l3.merge(l1,l2);
      break;
    case 4:
      cout<<"List 1: ";
      l1.display();
      cout<<"List 2: ";
      l2.display();
      cout<<"List 3: ";
      l3.display(); 
      break;
    case 5:
      cout<<"Exiting...";
      return 0;
    default:
      cout<<"Invalid Choice...";
      break;
    }
  }
}
