#include <iostream>
using namespace std;

/*Syed Wahaaj Ali
CT-24035
*/

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

    string toString() {
        // Converting stack to string (reverse order since stack = LIFO)
        string res = "";
        Node* curr = top;
        while (curr != nullptr) {
            res = curr->data + res; // prepend
            curr = curr->next;
        }
        return res;
    }
};

string processString(const string& str) {
    Stack s;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '#') {
            s.pop(); // backspace = remove last char
        } else {
            s.push(c);
        }
    }
    return s.toString();
}

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    string processedS = processString(s);
    string processedT = processString(t);

    cout << "First string becomes: " << processedS << endl;
    cout << "Second string becomes: " << processedT << endl;

    if (processedS == processedT) {
        cout << "The strings are equal after processing backspaces.\n";
    } else {
        cout << "The strings are NOT equal after processing backspaces.\n";
    }
    return 0;
}
