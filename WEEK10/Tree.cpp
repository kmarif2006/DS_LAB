#include<bits/stdc++.h>
using namespace std;
class Tree{
  class Node{
    public:
    int data;
    Node* left;
    Node* right;
    public:
    Node(int value){
      data=value;
      left=nullptr;
      right=nullptr;
    }
  };
  public:
  Node* root;
  public:
  Tree(){
    root=nullptr;
  }
  public:
  void insert(int value){
    if(root==nullptr){
      Node* node=new Node(value);
      root=node;
      return;
    }
    else{
      insertHelper(root,value);
    }
  }
  void insertHelper(Node* root,int value){
    char direction;
    cout<<"Left(L) or Right(R) of "<<root->data<<": ";
    cin>>direction;
    if(direction=='L'){
      if(root->left==nullptr){
        Node* node=new Node(value);
        root->left=node;
        return;
      }
      else{
        insertHelper(root->left,value);
      }
    }
    else if(direction=='R'){
      if(root->right==nullptr){
        Node* node=new Node(value);
        root->right=node;
        return;
      }
      else{
        insertHelper(root->right,value);
      }
    }
    else{
      cout<<"Invalid Input..";
      insertHelper(root,value);
    }
  }
  void preorder(Node* root){
    if(root==nullptr){
      return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
  void inorder(Node* root){
    if(root==nullptr){
      return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
  void postorder(Node* root){
    if(root==nullptr){
      return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
  }
  bool search(Node* root,int key){
    return searchHelper(root,key);
  }
  bool searchHelper(Node* root,int key){
    if(root==nullptr){
      return false;
    }
    if(root->data==key){
      return true;
    }
    return searchHelper(root->left,key)||searchHelper(root->right,key);
  }
};
int main() {
    Tree tree;
    int choice;
    int value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;

            case 2:
                tree.preorder(tree.root);
                break;

            case 3:
                tree.inorder(tree.root);
                break;

            case 4:
                tree.postorder(tree.root);
                break;

            case 5:
                cout << "Enter character to search: ";
                cin >> value;
                if (tree.search(tree.root,value)) {
                    cout << value << " found in the tree." << endl;
                } else {
                    cout << value << " not found in the tree." << endl;
                }
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}