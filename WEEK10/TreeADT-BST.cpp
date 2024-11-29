#include <iostream>
using namespace std;

class Tree {
private:
    class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root; 

public:
    Tree() {
        root = nullptr; 
    }

    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value); 
        } else {
            insertHelper(root, value); 
        }
    }

    void insertHelper(Node* node, int value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new Node(value); 
            } else {
                insertHelper(node->left, value); 
            }
        } else if (value > node->data) {
            if (node->right == nullptr) {
                node->right = new Node(value); 
            } else {
                insertHelper(node->right, value); 
            }
        } else {
            cout << "Number already exists." << endl; 
        }
    }

    void preorder(Node* node) {
        if (node == nullptr) {
            return; 
        }
        cout << node->data << " "; 
        preorder(node->left); 
        preorder(node->right); 
    }

    void inorder(Node* node) {
        if (node == nullptr) {
            return; 
        }
        inorder(node->left); 
        cout << node->data << " "; 
        inorder(node->right); 
    }

    void postorder(Node* node) {
        if (node == nullptr) {
            return; 
        }
        postorder(node->left); 
        postorder(node->right);
        cout << node->data << " ";
    }

    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false; 
        }
        if (node->data == value) {
            return true; 
        }
        
        return (value < node->data) ? search(node->left, value) : search(node->right, value);
    }

    
    void preorder() {
        preorder(root);
    }

    void inorder() {
        inorder(root);
    }

    void postorder() {
        postorder(root);
    }

    bool search(int value) {
        return search(root, value);
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
                cout << "Preorder Traversal: ";
                tree.preorder();
                cout << endl;
                break;

            case 3:
                cout << "Inorder Traversal: ";
                tree.inorder();
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();
                cout << endl;
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value)) {
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
