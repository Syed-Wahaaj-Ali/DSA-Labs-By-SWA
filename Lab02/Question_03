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
    // Merge two sorted lists (from Ex1)
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node dummy(0);
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

        if (list1) tail->next = list1;
        else tail->next = list2;

        return dummy.next;
    }

    // Sort list using Merge Sort
    Node* sortList(Node* head) {
        // Base case: 0 or 1 node
        if (head == nullptr || head->next == nullptr) return head;

        // Find middle using slow-fast pointer
        Node* slow = head;
        Node* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split list into two halves
        Node* rightHalf = slow->next;
        slow->next = nullptr;
        Node* leftHalf = head;

        // Recursively sort both halves
        Node* leftSorted = sortList(leftHalf);
        Node* rightSorted = sortList(rightHalf);

        // Merge sorted halves
        return mergeTwoLists(leftSorted, rightSorted);
    }

    // Print list
    void printList(Node* head) {
        while (head) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    // Unsorted list: 4 -> 2 -> 1 -> 3 -> 5
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(5);

    LinkedList obj;

    cout << "Original List: ";
    obj.printList(head);

    head = obj.sortList(head);

    cout << "Sorted List: ";
    obj.printList(head);

    return 0;
}
