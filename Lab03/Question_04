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

    Node(int data) {
        this->data = data;
        next = prev = nullptr;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = nullptr;
    }

    // insert a new node at the end
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

    // display list from head to tail
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
        if (!M.head) return;  // if M is empty, do nothing
        if (!head) {
            // if current list is empty, take M directly
            head = M.head;
            tail = M.tail;
        } else {
            // link current tail to M's head
            tail->next = M.head;
            M.head->prev = tail;
            tail = M.tail;
        }
    }

    // sort the list in descending order using bubble sort
    void sortDescending() {
        if (!head) return;

        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->data < ptr1->next->data) {
                    // swap data if in wrong order
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }

            lptr = ptr1; // last sorted node
        } while (swapped);
    }
};

int main() {
    DoublyList L, M;

    // add even numbers to L
    for (int i = 2; i <= 10; i += 2)
        L.insertEnd(i);

    // add odd numbers to M
    for (int i = 1; i <= 9; i += 2)
        M.insertEnd(i);

    cout << "List L: ";
    L.display();

    cout << "List M: ";
    M.display();

    // join M to L
    L.concatenate(M);

    cout << "Concatenated List N: ";
    L.display();

    // sort the combined list in descending order
    L.sortDescending();

    cout << "Sorted List N (Descending): ";
    L.display();

    return 0;
}
