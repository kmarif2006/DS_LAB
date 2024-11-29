#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr,int n){
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-2-i;j++){
            if(arr[j+1]<arr[j]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void selection_sort(vector<int>&arr,int n){
    for(int i=0;i<=n-1;i++){
        int mini=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[mini])mini=j;
        }
        int temp=arr[i];
        arr[i]=arr[mini];
        arr[mini]=temp;
    }
}
void counting_sort(vector<int>&arr,int n){
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest)largest=arr[i];
    }
    int hash_arr[largest+1]={0};
    for(int i=0;i<n;i++){
        hash_arr[arr[i]]++;
    }
    int index=0;
    for(int i=0;i<largest+1;i++){
        while(hash_arr[i]>0){
            arr[index++]=i;
            hash_arr[i]--;
        }
    }

}
void display(vector<int>&arr,int n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }

int main(){
    int size;
    char ch;
    while(true){
        cout<<"\nEnter the size of the array: ";
        cin>>size;
        vector<int> arr(size);
        for(int i=0;i<size;i++){
            cout<<"Element at index "<<i<<" :";
            cin>>arr[i];
        }
    
        cout<<"\na) Bubble Sort\nb) Selection Sort\nc) Counting Sort\nd) Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch){
            case 'a':{
                bubble_sort(arr,size);
                display(arr,size);
                break;
            }
            case 'b':{
                selection_sort(arr,size);
                display(arr,size);
                break;
            }
            case 'c':{
                counting_sort(arr,size);
                display(arr,size);
                break;
            }
            case 'd':{
                cout<<"Exiting...";
                return 0;
            }
            default:{
                cout<<"Invalid choice!!!";
                break;
            }
        }
    }
}