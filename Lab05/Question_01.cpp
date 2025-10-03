#include <iostream>
using namespace std;

/*
  Syed Wahaaj Ali
  CT-24035
*/

class MyCircularDeque {
private:
    int *arr;       // dynamic array to store elements
    int front;      // index of front element
    int rear;       // index of rear element
    int size;       // current number of elements
    int capacity;   // maximum capacity of deque

public:
    MyCircularDeque(int k) {
        arr = new int[k];
        capacity = k;
        size = 0;
        front = 0;
        rear = -1;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        if (size == 0) {   // if first element
            front = 0;
            rear = 0;
        } else {
            // move front backward (circularly)
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        if (size == 0) {   // if first element
            front = 0;
            rear = 0;
        } else {
            // move rear forward (circularly)
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        // move front forward (circularly)
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        // move rear backward (circularly)
        rear = (rear - 1 + capacity) % capacity;
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
        delete[] arr;  // free allocated memory
    }
};

int main() {
    MyCircularDeque dq(3);

    cout << dq.insertLast(1) << endl;  // 1
    cout << dq.insertLast(2) << endl;  // 1
    cout << dq.insertFront(3) << endl; // 1
    cout << dq.insertFront(4) << endl; // 0 (full)
    cout << dq.getRear() << endl;      // 2
    cout << dq.isFull() << endl;       // 1
    cout << dq.deleteLast() << endl;   // 1
    cout << dq.insertFront(4) << endl; // 1
    cout << dq.getFront() << endl;     // 4
}
