#include<iostream>
#include<string>
#include<algorithm>
#include"stack.h"
using namespace std;
string removeplus(string s){
  Stack st;
  string ans;
  for(int i=0;i<s.length();i++){
    if(s[i]!='+'){
      st.push(s[i]);
    }else{
      if(!st.empty()){
        st.pop();
      }
    }
  }
  while(!st.empty()){
    char ch=st.pop();
    ans+=ch;
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
int main(){
  string input;
  cout<<"Enter a input string containing('+')characters: ";
  cin>>input;
  cout<<"Removed '+' from the string: "<<removeplus(input);
}