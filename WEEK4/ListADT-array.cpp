#include<bits/stdc++.h>
using namespace std;
class List{
    int *arr;
    int capacity;
    int size;
public:
  List(int cap){
    capacity=cap;
    arr=new int[capacity];
    size=0;
  }

public:
void insertAtBeginning(int value){
    if(size==capacity){
        cout<<"List is full\n";
        return;
    }
    for(int i=size;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=value;
    size++;
}
void insertAtEnd(int value){
    if(size==capacity){
        cout<<"List is full\n";
        return;
    }
    arr[size]=value;
    size++;
}
void insertAtPosition(int pos,int value){
    if(size==capacity){
        cout<<"List is full\n";
        return;
    }
    if (pos < 0 || pos > size ) {
            cout << "Invalid position!\n";
            return;
        }
    for(int i=size;i>pos;i++){
        arr[i]=arr[i-1];
    }
    arr[pos]=value;
    size++;
}
void removeFromBeginning(){
    if (size == 0) {
            cout << "List is empty!\n";
            return;
        }
    for(int i=0;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
}
void removeFromEnd(){
    if (size == 0) {
            cout << "List is empty!\n";
            return;
        }
    size--;
}
void removeFromPosition(int pos){
    if(size==0){
        cout<<"List is empty!\n";
        return;
    }
    if (pos < 0 || pos >= size ) {
            cout << "Invalid position!\n";
            return;
        }
    for(int i=pos;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
}
void search(int value){
    for(int i=0;i<size;i++){
        if(arr[i]==value){
            cout<<"\nElement found at index "<<i;
            return;
        }
    }
    cout<<"Element not found";
}
void display(){
    if(size==0){
        cout<<"List is empty";
        return;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

};
int main(){
    int capacity,pos,value;
    cout<<"\nEnter the size of the list: ";
    cin>>capacity;
    List list(capacity);
    int choice;
    while(true){
        cout << "\nThese are the list implementations:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Remove from Beginning\n";
        cout << "5. Remove from End\n";
        cout << "6. Remove from Position\n";
        cout << "7. Display List\n";
        cout << "8. Search Element\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            cout << "\nEnter the value to insert at the beginning: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "\nEnter the value to insert at the end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "\nEnter the position to insert (0-based indexing): ";
            cin >> pos;
            cout << "\nEnter the value to insert: ";
            cin >> value;
            list.insertAtPosition(pos, value);
            break;
        case 4:
            list.removeFromBeginning();
            break;
        case 5:
            list.removeFromEnd();
            break;
        case 6:
            cout << "\nEnter the position to remove (0-based indexing): ";
            cin >> pos;
            list.removeFromPosition(pos);
            break;
        case 7:
            list.display();
            break;
        case 8:
            cout << "\nEnter the value to search: ";
            cin >> value;
            list.search(value);
            break;
        case 9:
            cout << "\nExiting...\n";
            return 0;
        default:
            cout << "\nInvalid choice! Please try again.\n";
        }
    }
}
  
