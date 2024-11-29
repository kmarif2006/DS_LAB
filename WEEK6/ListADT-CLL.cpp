#include<bits/stdc++.h>
using namespace std;
class List{
    class Node{
        public:
        int data;
        Node* next;
        public:
        Node(int value){
            data=value;
            next=nullptr;
        }
    };
public:
    Node* head;
    int size;
public:
    List(){
        head=nullptr;
        size=0;
    }

public:
Node* insertBegin(Node* head,int value){
    Node* node=new Node(value);
    if(head==nullptr){
        size++;
        head=node;
        head->next=head;
        return head;
    }
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node->next=temp->next;
    temp->next=node;
    size++;
    return node;
}
Node* insertEnd(Node* head,int value){
    Node* node=new Node(value);
    if(head==nullptr){
        size++;
        head=node;
        head->next=head;
        return head;
    }
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=node;
    node->next=head;
    size++;
    return head;
}
Node* insertPosition(Node* head,int value,int position){
    if(position<0||position>size){
        cout<<"Invalid position\n";
        return head;
    }
    if(position==0){
        return insertBegin(head,value);
    }
    if(position==size){
        return insertEnd(head,value);
    }
    Node* temp=head;
    for(int i=1;i<position;i++){
        temp=temp->next;
    }
    Node* node=new Node(value);
    size++;
    node->next=temp->next;
    temp->next=node;
    return head;
}
Node* deleteBegin(Node* head){
    if(head==nullptr){
        cout<<"List is empty\n";
        return nullptr;
    }
    if(head->next==head){
        delete head;
        size--;
        return nullptr;
    }
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    Node* deleteNode=head;
    head=head->next;
    temp->next=head;
    delete deleteNode;
    size--;
    return head;
} 
void display(Node* head){
    if(head==nullptr){
        cout<<"List is empty\n";
        return;
    }
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}
Node* deleteEnd(Node* head){
    if(head==nullptr){
        cout<<"List is empty\n";
        return nullptr;
    }
    if(head->next==head){
        delete head;
        size--;
        return nullptr;
    }
    Node* temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    Node* deleteNode=temp->next;
    temp->next=head;
    delete deleteNode;
    size--;
    return head;
}
Node* deletePosition(Node* head,int position){
    if(position<0||position>=size){
        cout<<"Invalid position.\n";
        return head;
    }
    if(head==nullptr){
        cout<<"list is empty\n";
        return nullptr;
    }
    if(head->next==head){
        delete head;
        size--;
        return nullptr;
    }
    if(position==0){
        return deleteBegin(head);
    }
    if(position==size-1){
        return deleteEnd(head);
    }
    Node* temp=head;
    for(int i=1;i<position;i++){
        temp=temp->next;
    }
    Node* deleteNode=temp->next;
    temp->next=temp->next->next;
    delete deleteNode;
    size--;
    return head;
}
void search(Node* head,int key){
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp=head;
    int index=0;
    do{
        if(temp->data==key){
            cout<<"Element is found at index "<<index<<"\n";
            return;
        }
        temp=temp->next;
        index++;
    }while(temp!=head);
    cout<<"Element is not found\n";
}

};
int main(){
    List list;
    int choice,value,position;
    while(true){
        cout<<"\n1.Insert Beginning\n2.Insert End\n3.Insert position\n4.Delete Beginning\n5.Delete End\n6.Delete Position\n7.Search\n8.Display\n9.Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter value to insert: ";
                cin>>value;
                list.head=list.insertBegin(list.head,value);
                break;
            }
            case 2:{
                cout<<"Enter value to insert: ";
                cin>>value;
                list.head=list.insertEnd(list.head,value);
                break;
            }
            case 3:{
                cout<<"Enter value to insert: ";
                cin>>value;
                cout<<"Enter the position to insert: ";
                cin>>position;
                list.head=list.insertPosition(list.head,value,position);
                break;
            }
            case 4:{
                list.head=list.deleteBegin(list.head);
                break;
            }
            case 5:{
                list.head=list.deleteEnd(list.head);
                break;
            }
            case 6:{
                cout<<"Enter the position to delete: ";
                cin>>position;
                list.head=list.deletePosition(list.head,position);
                break;
            }
            case 7:{
                int key;
                cout<<"Enter the element to search: ";
                cin>>key;
                list.search(list.head, key);
                break;
            }
            case 8:{
                list.display(list.head);
                break;
            }
            case 9:{
                cout<<"Exiting...";
                return 0;
            }
            default:{
                cout<<"Enter valid choice";
                break;
            }
        }
    }
}