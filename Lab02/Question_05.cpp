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

class CircularQueue {
private:
    Node* front;
    Node* rear;
public:
    CircularQueue() {
        front = rear = nullptr;
    }

    // Enqueue: add at rear
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!front) { // empty queue
            front = rear = newNode;
            rear->next = front; // circular link
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // keep it circular
        }
        cout << val << " enqueued\n";
    }

    // Dequeue: remove from front
    void dequeue() {
        if (!front) {
            cout << "Queue is empty!\n";
            return;
        }
        if (front == rear) { // only one element
            cout << front->data << " dequeued\n";
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            cout << front->data << " dequeued\n";
            front = front->next;
            rear->next = front; // maintain circular
            delete temp;
        }
    }

    // Peek front element
    int peek() {
        if (!front) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }

    // Display
    void display() {
        if (!front) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Front element = " << q.peek() << endl;
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // extra dequeue test
    return 0;
}
