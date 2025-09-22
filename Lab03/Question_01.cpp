// Syed Wahaaj Ali
// CT-24035

#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;

		// constructor to set value and initialize next as null
		Node(int data) {
			this->data = data;
			next = nullptr;
		}
};

// Circular Queue using linked list
class CircularQueue {
	private:
		Node* front;
		Node* rear;

	public:
		// constructor to initialize empty queue
		CircularQueue() {
			front = rear = nullptr;
		}

		// checks if queue is empty
		bool isEmpty() {
			return front == nullptr;
		}

		// adds an element to the rear of the queue
		void enqueue(int val) {
			Node* n = new Node(val);
			if (isEmpty()) {
				// if empty, front and rear both point to new node
				front = rear = n;
				n->next = front; // make it circular
			} else {
				n->next = front;     // new node points to front
				rear->next = n;      // old rear points to new node
				rear = n;            // update rear
			}
		}

		// removes element from the front
		void dequeue() {
			if (isEmpty()) {
				cout << "Queue is Empty\n";
				return;
			}

			if (front == rear) {
				delete front;
				front = rear = nullptr;
			} else {
				Node* temp = front;
				front = front->next;   // move front ahead
				rear->next = front;    // fix the circular link
				delete temp;
			}
		}

		// returns the front element without removing it
		int peek() {
			if (isEmpty()) {
				cout << "Queue is Empty\n";
				return -1;   // or throw an exception
			}
			return front->data;
		}

		// prints all elements in the queue
		void display() {
			if (isEmpty()) {
				cout << "Queue is Empty\n";
				return;
			}

			Node* current = front;
			do {
				cout << current->data << " ";
				current = current->next;
			} while (current != front);
			cout << endl;
		}
};

int main() {
	CircularQueue cq;

	cq.enqueue(10);  // add 10
	cq.enqueue(20);  // add 20
	cq.enqueue(30);  // add 30
	cq.display();    // should print 10 20 30

	cq.dequeue();    // remove front (10)
	cq.display();    // should print 20 30

	cout << "Front element = " << cq.peek() << endl;

	cq.enqueue(40);  // add 40
	cq.enqueue(50);  // add 50
	cq.display();    // should print 20 30 40 50

	return 0;
}
