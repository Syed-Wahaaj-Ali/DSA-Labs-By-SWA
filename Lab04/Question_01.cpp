#include <iostream>
using namespace std;

// Syed Wahaaj Ali
// CT-24035

struct Node {
    char data;
    Node* next;
    Node(char val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    void push(char val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            return '\0';  // return null char if stack empty
        }
        Node* temp = top;
        char val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool isPalindrome(string str) {
    Stack s;
  
    // Push all characters onto the stack
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
  
    // Pop and compare with original characters
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != s.pop()) {
            return false;
        }
    }
    return true;
}

int main() {
    string a;
    cout << "Enter a string: ";
    cin >> a;

    if (isPalindrome(a)) {
        cout << "The string is a palindrome.\n";
    } else {
        cout << "The string is NOT a palindrome.\n";
    }
    return 0;
}
