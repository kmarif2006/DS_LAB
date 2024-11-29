#include <iostream>
#include <string>
#include "stack.h"
using namespace std;


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '=') return 0; 
    return -1;
}

string infixToPostfix(string infix) {
    Stack st;
    string postfix;
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch; 
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop(); 
        } else { 
            while (!st.empty() && precedence(st.peek()) >= precedence(ch)) {
                postfix += st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        postfix += st.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) {
    Stack st;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int val2 = st.pop();
            int val1 = st.pop();
            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '=': st.push(val2); break; 
            }
        }
    }
    return st.pop();
}

int main() {
    string infix, postfix;
    int choice;
    while (true) {
        cout << "\n1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a valid infix expression: ";
                cin >> infix;
                break;
            case 2:
                postfix = infixToPostfix(infix);
                cout << "Postfix expression: " << postfix << endl;
                break;
            case 3:
                if (postfix.empty()) {
                    cout << "Convert to postfix first." << endl;
                } else {
                    cout << "Result of postfix evaluation: " << evaluatePostfix(postfix) << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
