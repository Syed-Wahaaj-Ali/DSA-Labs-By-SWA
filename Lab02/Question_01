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
		Node* mergeTwoLists(Node* list1, Node* list2) {
			Node dummy(0); // dummy node to simplify logic
			Node* tail = &dummy;

			while (list1 && list2) {
				if (list1->data <= list2->data) {
					tail->next = list1;
					list1 = list1->next;
				} else {
					tail->next = list2;
					list2 = list2->next;
				}
				tail = tail->next;
			}

			// attach the remaining nodes
			if (list1) {
				tail->next = list1;
			} else {
				tail->next = list2;
			}

			return dummy.next;
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
	// First sorted list: 1 -> 3 -> 5 -> 7
	Node* list1 = new Node(1);
	list1->next = new Node(3);
	list1->next->next = new Node(5);
	list1->next->next->next = new Node(7);

	// Second sorted list: 2 -> 4 -> 6 -> 8 -> 10
	Node* list2 = new Node(2);
	list2->next = new Node(4);
	list2->next->next = new Node(6);
	list2->next->next->next = new Node(8);
	list2->next->next->next->next = new Node(10);

	LinkedList obj;
	Node* merged = obj.mergeTwoLists(list1, list2);

	cout << "Merged Sorted List: ";
	obj.printList(merged);

	return 0;
}
