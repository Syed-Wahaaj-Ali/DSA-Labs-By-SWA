// Syed Wahaaj Ali
// CT-24035

#include <iostream>
using namespace std;

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

class Deque {
private:
    Node* front;
    Node* rear;

public:
    // constructor to start with empty deque
    Deque() {
        front = rear = nullptr;
    }

    // returns true if deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // insert at the front
    void insertFront(int val) {
        Node* n = new Node(val);
        if (isEmpty()) {
            // if empty, both front and rear are same
            front = rear = n;
        } else {
            n->next = front;
            front->prev = n;
            front = n;
        }
    }

    // insert at the rear
    void insertRear(int val) {
        Node* n = new Node(val);
        if (isEmpty()) {
            front = rear = n;
        } else {
            rear->next = n;
            n->prev = rear;
            rear = n;
        }
    }

    // delete from front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        Node* temp = front;

        if (front == rear) {
            // only one element
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
    }

    // delete from rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        Node* temp = rear;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;
    }

    // display all elements from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        Node* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.display();        // output: 5 10 20

    dq.deleteFront();
    dq.display();        // output: 10 20

    dq.deleteRear();
    dq.display();        // output: 10

    return 0;
}
