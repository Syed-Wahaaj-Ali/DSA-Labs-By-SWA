/*
    Syed Wahaaj Ali
    CT-24035
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top; // top of stack
public:
    Stack() {
        top = nullptr;
    }

    // Push = insert at head
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << val << " pushed\n";
    }

    // Pop = remove from head
    void pop() {
        if (!top) {
            cout << "Stack is empty!\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped\n";
        top = top->next;
        delete temp;
    }

    // Peek = see top
    int peek() {
        if (!top) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    // Display
    void display() {
        if (!top) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack: ";
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.display();
    cout << "Top element = " << s.peek() << endl;
    s.pop();
    s.display();
    s.pop();
    s.pop();
    s.pop(); // extra pop test
    return 0;
}
