#include<bits/stdc++.h>
#include"BrowserHistory.h"
using namespace std;
int main(){
  webbrowser wb;
  int value,choice;
  while(true){
            cout << "\n1. New Webpage\n2. Front\n3. Back\n4. Exit\nEnter your choice: ";
            cin>>choice;
            switch(choice){
              case 1:{
                cout<<"Enter webpage data:  ";
                cin>>value;
                wb.new_webpage(value);
                break;
              }
              case 2:{
                wb.front();
                wb.displayCurrent();
                break;
              }
              case 3:{
                wb.back();
                wb.displayCurrent();
                break;
              }
              case 4:{
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