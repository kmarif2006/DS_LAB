//Write a C++ menu-driven program to sort an array of numbers in ascending or descending order
#include<bits/stdc++.h>
using namespace std;

void ascending_order(int arr[],int size){
    int min_index;
    for(int i=0;i<=size-2;i++){
        min_index=i;
        for(int j=i;j<=size-1;j++){
            if(arr[j]<arr[min_index])min_index=j;
        }
        swap(arr[i],arr[min_index]);
    }
}
void descending_order(int arr[],int size){
    int max_index;
    for(int i=0;i<=size-2;i++){
        max_index=i;
        for(int j=i;j<=size-1;j++){
            if(arr[j]>arr[max_index])max_index=j;
        }
        swap(arr[i],arr[max_index]);
    }
}
void print_array(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    int ch;
    cout<<"1.Ascending order\n2.Decending order\nEnter your choice: ";
    cin>>ch;
    switch(ch){
        case 1:{
            ascending_order(arr,size);
            print_array(arr,size);
            break;
        }
        case 2:{
            descending_order(arr,size);
            print_array(arr,size);
            break;
        }
        default:{
            cout<<"Invalid choice!!";
            break;
        }
    }
    return 0;
}