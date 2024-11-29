//Write a C++ program to search for the presence of a number in an array using linear search.
#include<bits/stdc++.h>
using namespace std;

int linear_search(int arr[],int key,int size){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter value at "<<i<< " index: ";
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the value to search: ";
    cin>>key;
    int index=linear_search(arr,key,size);
    if(index!=-1){
        cout<<"Element found at index "<<index;
    }else{
        cout<<"Element not found in the array";
    }
    return 0;
}