//  Convert the sorting program into a header file and import it into a new cpp file. Write a C++ menu-driven program for binary search in this new cpp file. Utilize the imported sort function to sort the input array before performing a binary search.

// The menu-driven program supports,

//      1. Sort

//      2. Binary Search

//      3. Exit

#include<bits/stdc++.h>
#include "sorting.h"
using namespace std;

int binary_search(int arr[],int size, int key){
    int low=0;
    int high=size-1;
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==key)return mid;
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int ch;
    while(ch!=3){
        int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
        cout<<"\n1.Sort\n2.Binary Search\n3.Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:{
                char sort_ch;
                cout<<"a.Ascending Sort\nb.Descending Sort\nEnter your choice: ";
                cin>>sort_ch;
                if(sort_ch=='a'){
                    ascending_order(arr,size);
                    cout << "Array after ascending sort: ";
                    print_array(arr,size);
                }
                else if(sort_ch=='b'){
                    descending_order(arr,size);
                    cout << "Array after descending sort: ";
                    print_array(arr,size);
                }
                else{
                    cout<<"Inavlid choice";
                }
                break;
            }
            case 2:{
                int key;
                cout<<"Enter the value to search in the array: ";
                cin>>key;
                int index=binary_search(arr,size,key);
                if(index!=-1){
                    cout<<"Element is found at index "<<index;
                }
                else{
                    cout<<"Element not found";
                }
                break;
            }
            case 3:{
                break;
            }
            default:{
                cout<<"Invalid choice";
                break;
            }
        }
    }
    return 0;
}