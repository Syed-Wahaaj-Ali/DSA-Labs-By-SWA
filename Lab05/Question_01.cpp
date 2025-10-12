#include <iostream>
using namespace std;

/*
  Syed Wahaaj Ali
  CT-24035
*/

class MyCircularDeque {
private:
    int *arr;       // Array to store elements
    int front;      // Index of front element
    int rear;       // Index of rear element
    int size;       // Current number of elements
    int capacity;   // Maximum capacity

public:
    MyCircularDeque(int k) {
        arr = new int[k];
        capacity = k;
        size = 0;
        front = 0;
        rear = -1;   // Empty deque state
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        if (size == 0) {
            front = 0;
            rear = 0;
        } else {
            // Move front backward circularly
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        if (size == 0) {
            front = 0;
            rear = 0;
        } else {
            // Move rear forward circularly
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        if (size == 1) {
            // Reset to empty state
            front = 0;
            rear = -1;
        } else {
            // Move front forward circularly
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        if (size == 1) {
            // Reset to empty state
            front = 0;
            rear = -1;
        } else {
            // Move rear backward circularly
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    ~MyCircularDeque() {
        delete[] arr;
    }
};

int main() {
    MyCircularDeque* mcq = new MyCircularDeque(3);

    if (mcq->insertLast(1)) {
        cout << "Inserted 1 at rear." << endl;
    } else {
        cout << "Failed to insert 1 at rear." << endl;
    }

    if (mcq->insertLast(2)) {
        cout << "Inserted 2 at rear." << endl;
    } else {
        cout << "Failed to insert 2 at rear." << endl;
    }

    if (mcq->insertFront(3)) {
        cout << "Inserted 3 at front." << endl;
    } else {
        cout << "Failed to insert 3 at front." << endl;
    }

    if (mcq->insertFront(4)) {
        cout << "Inserted 4 at front." << endl;
    } else {
        cout << "Failed to insert 4 at front." << endl;
    }

    cout << "Rear element: " << mcq->getRear() << endl;

    if (mcq->isFull())
        cout << "Deque is full." << endl;
    else
        cout << "Deque is not full." << endl;

    if (mcq->deleteLast())
        cout << "Deleted last element." << endl;
    else
        cout << "Failed to delete last element." << endl;

    if (mcq->insertFront(4)) {
        cout << "Inserted 4 at front." << endl;
    } else {
        cout << "Failed to insert 4 at front." << endl;
    }

    cout << "Front element: " << mcq->getFront() << endl;

    delete mcq;
    return 0;
}
