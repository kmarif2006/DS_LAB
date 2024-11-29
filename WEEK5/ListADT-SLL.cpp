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
        if(head==nullptr){
            size++;
            return new Node(value);
        }
        Node *node=new Node(value);
        node->next=head;
        head=node;
        size++;
        return head;
    }
    void display(Node* head){
        if(head==nullptr){
            cout<<"List is empty";
            return;
        }
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    Node* insertEnd(Node* head,int value){
        if(head==nullptr){
            return new Node(value);
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        Node* node=new Node(value);
        temp->next=node;
        size++;
        return head;
    }
    Node* insertPosition(Node* head,int value,int position){
        if(position<0||position>size){
            cout<<"Invalid position";
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
        Node* nodetopoint=temp->next;
        temp->next=node;
        node->next=nodetopoint;
        size++;
        return head;
    }
    Node* deleteBegin(Node* head){
        if(head==nullptr){
            cout<<"List is empty";
            return head;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
        size--;
        return head;
    }
    Node* deleteEnd(Node* head){
        if(head==nullptr){
            return nullptr;
        }
        if(head->next==nullptr){
            delete head;
            size--;
            return nullptr;
        }
        Node* temp=head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        Node* deleteNode=temp->next;
        temp->next=nullptr;
        delete deleteNode;
        size--;
        return head;
    }
    Node* deletePosition(Node* head,int position){
        if(head==nullptr){
            return nullptr;
        }
        if(position<0||position>=size){
            cout<<"Invalid Position";
            return head;
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
        Node* deletenode=temp->next;
        temp->next=temp->next->next;
        delete deletenode;
        size--;
        return head;
    }
    void search(Node* head,int key){
        Node* temp=head;
        int index=0;
        while(temp!=nullptr){
            if(temp->data==key){
                cout<<"Element is found at index "<<index;
                return;
            }
            index++;
            temp=temp->next;
            
        }
        if(temp==nullptr){
            cout<<"Element not found";
            return;
        }
    }
    void displayReverse(Node* head){
        Node* temp=head;
        if(temp==nullptr){
            return;
        }
        displayReverse(temp->next);
        cout<<temp->data<<" ";
    }
    Node* reverseLink(Node* head){
        Node* temp=head;
        Node* prev=nullptr;
        while(temp!=nullptr){
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

};
int main(){
    List list;
    int choice,value,position;
    while(true){
        cout<<"\n1.Insert Beginning\n2.Insert End\n3.Insert position\n4.Delete Beginning\n5.Delete End\n6.Delete Position\n7.Search\n8.Display\n9.Display Reverse\n10.Reverse Link\n11.Exit\nEnter your choice: ";
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
                list.displayReverse(list.head);
                break;
            }
            case 10:{
                list.head=list.reverseLink(list.head);
                break;
            }
            case 11:{
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