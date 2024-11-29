#ifndef sorting
#define sorting
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
#endif