#include<bits/stdc++.h>
#include"stack.h"
using namespace std;
bool is_balanced_parentheses(string s){
  Stack st;
  for(int i=0;i<s.length();i++){
    if(s[i]=='('||s[i]=='['||s[i]=='{'){
      st.push(s[i]);
    }
    else{
      if(st.empty()){
        return false;
      }
      char ch=st.pop();
      if(ch=='('&&s[i]!=')')return false;
      if(ch=='['&&s[i]!=']')return false;
      if(ch=='{'&&s[i]!='}')return false;
    }
  }
  return st.empty();
}
int main(){
int choice;
string input;
while(true){
  cout<<"\n1.Check Balance\n2.Exit\nEnter Your Choice: ";
  cin>>choice;
  switch(choice){
    case 1:{
      cout<<"Enter the string of parentheses: ";
      cin>>input;
      if(is_balanced_parentheses(input)){
        cout<<"The parentheses are balanced.\n";
      }else{
        cout<<"The parentheses are not balanced.\n";
      }
      break;
    }
    case 2:{
      cout<<"Exiting...";
      return 0;
      break;
    }
    default:{
      cout<<"Invalid Choice. Please try again.\n";
      break;
    }
  }
}
}