// Syed Wahaaj Ali
// CT-24035

#include <iostream>
using namespace std;

// Node of a doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // constructor to initialize data and pointers
    Node(int data) {
        this->data = data;
        next = prev = nullptr;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    // constructor to start with empty list
    DoublyList() {
        head = tail = nullptr;
    }

    // insert a node at the end of the list
    void insertEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    // print all elements from head to tail
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // concatenate another list M to the current list
    void concatenate(DoublyList& M) {
        if (!M.head) return;  // if M is empty, nothing to do
        if (!head) {
            // if current list is empty, just take M as it is
            head = M.head;
            tail = M.tail;
        } else {
            // link the end of current list to start of M
            tail->next = M.head;
            M.head->prev = tail;
            tail = M.tail;
        }
    }
};

int main() {
    DoublyList L, M;

    // fill L with even numbers
    for (int i = 2; i <= 10; i += 2) L.insertEnd(i);

    // fill M with odd numbers
    for (int i = 1; i <= 9; i += 2) M.insertEnd(i);

    cout << "List L: ";
    L.display();

    cout << "List M: ";
    M.display();

    // combine M into L
    L.concatenate(M);

    cout << "Concatenated List N: ";
    L.display();

    return 0;
}
