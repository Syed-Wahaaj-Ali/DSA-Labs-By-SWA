#include <iostream>
#include <string>
using namespace std;

/*
  Syed Wahaaj Ali
  CT-24035
*/

class EmployeeNode {
	public:
		int id;
		string name;
		string department;
		EmployeeNode* left;
		EmployeeNode* right;

		EmployeeNode(int id, string name, string department) {
			this->id = id;
			this->name = name;
			this->department = department;
			left = nullptr;
			right = nullptr;
		}
};

class EmployeeBST {
	public:
		EmployeeNode* root;

		EmployeeBST() {
			root = nullptr;
		}

		void insert(int id, string name, string department) {
			EmployeeNode* newNode = new EmployeeNode(id, name, department);
			if (root == nullptr) {
				root = newNode;
				return;
			}

			EmployeeNode* current = root;
			EmployeeNode* parent = nullptr;

			while (current != nullptr) {
				parent = current;
				if (id < current->id)
					current = current->left;
				else if (id > current->id)
					current = current->right;
				else {
					cout << "Duplicate ID not allowed: " << id << endl;
					return;
				}
			}

			if (id < parent->id)
				parent->left = newNode;
			else
				parent->right = newNode;
		}

		void inOrderTraversal(EmployeeNode* node) {
			if (node == nullptr)
				return;
			inOrderTraversal(node->left);
			cout << "ID: " << node->id << " | Name: " << node->name << " | Department: " << node->department << endl;
			inOrderTraversal(node->right);
		}

		void inOrder() {
			if (root == nullptr) {
				cout << "Tree is empty.\n";
				return;
			}
			inOrderTraversal(root);
		}

		EmployeeNode* searchNode(EmployeeNode* node, int id) {
			if (node == nullptr)
				return nullptr;
			if (id == node->id)
				return node;
			else if (id < node->id)
				return searchNode(node->left, id);
			else
				return searchNode(node->right, id);
		}

		void search(int id) {
			EmployeeNode* result = searchNode(root, id);

			if (result == nullptr)
				cout << "Employee with ID " << id << " not found.\n";
			else
				cout << "Found ID: " << result->id << " | Name: " << result->name << " | Department: " << result->department << endl;
		}

		EmployeeNode* findMinNode(EmployeeNode* node) {
			while (node->left != nullptr)
				node = node->left;
			return node;
		}

		void findMin() {
			if (root == nullptr) {
				cout << "Tree is empty.\n";
				return;
			}
			EmployeeNode* smallest = findMinNode(root);
			cout << "Min ID: " << smallest->id << " | Name: " << smallest->name << " | Department: " << smallest->department << endl;
		}

		void findMax() {
			if (root == nullptr) {
				cout << "Tree is empty.\n";
				return;
			}
			EmployeeNode* node = root;
			while (node->right != nullptr)
				node = node->right;
			cout << "Max ID: " << node->id << " | Name: " << node->name << " | Department: " << node->department << endl;
		}

		EmployeeNode* deleteRec(EmployeeNode* node, int id) {
			if (node == nullptr) {
				cout << "Employee not found: " << id << endl;
				return nullptr;
			}

			if (id < node->id)
				node->left = deleteRec(node->left, id);
			else if (id > node->id)
				node->right = deleteRec(node->right, id);
			else {
				if (node->left == nullptr && node->right == nullptr) {
					delete node;
					return nullptr;
				} else if (node->left == nullptr) {
					EmployeeNode* temp = node->right;
					delete node;
					return temp;
				} else if (node->right == nullptr) {
					EmployeeNode* temp = node->left;
					delete node;
					return temp;
				} else {
					EmployeeNode* successor = findMinNode(node->right);
					node->id = successor->id;
					node->name = successor->name;
					node->department = successor->department;
					node->right = deleteRec(node->right, successor->id);
				}
			}
			return node;
		}

		void deleteNode(int id) {
			root = deleteRec(root, id);
		}
};

int main() {
	EmployeeBST t;
	t.insert(30, "Ali", "Sales");
	t.insert(15, "Ahmed", "IT");
	t.insert(40, "Ayaan", "Finance");
	t.insert(10, "Bilal", "HR");
	t.insert(50, "Sara", "Admin");

	cout << "\nInorder Traversal (Ascending by ID):\n";
	t.inOrder();
	cout << "\nSearching ID 15:\n";
	t.search(15);
	cout << "\nMinimum Employee ID:\n";
	t.findMin();
	cout << "\nMaximum Employee ID:\n";
	t.findMax();
	cout << "\nDeleting ID 30...\n";
	t.deleteNode(30);
	cout << "\nAfter Deletion:\n";
	t.inOrder();
	return 0;
}
