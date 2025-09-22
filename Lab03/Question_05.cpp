// Syed Wahaaj Ali
// CT-24035

#include <iostream>
using namespace std;

// Node of Doubly Linked List
class Node {
public:
    string url;
    Node* next;
    Node* prev;

    Node(string u) {
        url = u;
        next = prev = nullptr;
    }
};

// Browser History using Doubly Linked List
class BrowserHistory {
    Node* current; // pointer to current page

public:
    // constructor with homepage
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    // visit a new page
    void visit(string url) {
        // clear forward history
        if (current->next != nullptr) {
            Node* temp = current->next;
            while (temp != nullptr) {
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
            current->next = nullptr;
        }

        // create and link new page
        Node* newPage = new Node(url);
        current->next = newPage;
        newPage->prev = current;
        current = newPage;
    }

    // go back by given steps
    string back(int steps) {
        while (current->prev != nullptr && steps > 0) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    // go forward by given steps
    string forward(int steps) {
        while (current->next != nullptr && steps > 0) {
            current = current->next;
            steps--;
        }
        return current->url;
    }

    // print the full browsing history
    void printHistory() {
        // move to the beginning
        Node* temp = current;
        while (temp->prev != nullptr) temp = temp->prev;

        cout << "History: ";
        while (temp != nullptr) {
            // mark current page with brackets
            if (temp == current) cout << "[" << temp->url << "] ";
            else cout << temp->url << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Driver
int main() {
    BrowserHistory bh("google.com");

    bh.visit("youtube.com");
    bh.visit("twitter.com");
    bh.visit("amazon.com");
    bh.visit("netflix.com");
    bh.visit("github.com");
    bh.printHistory();

    cout << "Back(2): " << bh.back(2) << endl;
    bh.printHistory();

    cout << "Forward(1): " << bh.forward(1) << endl;
    bh.printHistory();

    bh.visit("stackoverflow.com");
    bh.printHistory();

    cout << "Back(3): " << bh.back(3) << endl;
    bh.printHistory();

    cout << "Forward(2): " << bh.forward(2) << endl;
    bh.printHistory();

    return 0;
}
