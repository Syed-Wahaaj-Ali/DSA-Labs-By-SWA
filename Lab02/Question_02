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

class LinkedList {
	public:
		Node* deleteDuplicates(Node* head) {
			Node* current = head;

			while (current != NULL && current->next != NULL) {
				if (current->data == current->next->data) {
					// Duplicate found? remove next node
					Node* duplicate = current->next;
					current->next = current->next->next;
					delete duplicate;  // free memory
				} else {
					// Move forward if no duplicate
					current = current->next;
				}
			}

			return head;
		}

		void printList(Node* head) {
			while (head) {
				cout << head->data << " ";
				head = head->next;
			}
			cout << endl;
		}
};

int main() {
	// Sorted list with duplicates: 1 -> 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 4 -> 5
	Node* head = new Node(1);
	head->next = new Node(1);
	head->next->next = new Node(2);
	head->next->next->next = new Node(3);
	head->next->next->next->next = new Node(3);
	head->next->next->next->next->next = new Node(4);
	head->next->next->next->next->next->next = new Node(4);
	head->next->next->next->next->next->next->next = new Node(4);
	head->next->next->next->next->next->next->next->next = new Node(5);

	LinkedList obj;

	cout << "Original List: ";
	obj.printList(head);

	head = obj.deleteDuplicates(head);

	cout << "After Removing Duplicates: ";
	obj.printList(head);

	return 0;
}
