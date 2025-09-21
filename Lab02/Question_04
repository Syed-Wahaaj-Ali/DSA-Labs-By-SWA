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
    // reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; // new head
    }

    // Check if list is palindrome
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        // 1. Find middle
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        Node* secondHalfStart = reverseList(slow->next);

        // 3. Compare both halves
        Node* firstPointer = head;
        Node* secondPointer = secondHalfStart;
        bool result = true;
        while (secondPointer) {
            if (firstPointer->data != secondPointer->data) {
                result = false;
                break;
            }
            firstPointer = firstPointer->next;
            secondPointer = secondPointer->next;
        }

        // 4. Restore the list 
        slow->next = reverseList(secondHalfStart);

        return result;
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
    // Palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    LinkedList obj;

    cout << "Original List: ";
    obj.printList(head);

    if (obj.isPalindrome(head))
        cout << "The list is a palindrome." << endl;
    else
        cout << "The list is NOT a palindrome." << endl;

    cout << "List after check (restored): ";
    obj.printList(head);

    return 0;
}
