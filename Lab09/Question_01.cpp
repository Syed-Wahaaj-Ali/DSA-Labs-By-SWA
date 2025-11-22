#include <iostream>
#include <stack>
using namespace std;

/*
  Syed Wahaaj Ali
  CT-24035
*/

class TreeNode {
	public:
		int val;
		TreeNode* left;
		TreeNode* right;

		TreeNode(int value) {
			val = value;
			left = nullptr;
			right = nullptr;
		}
};

class BinarySearchTree {
	public:
		TreeNode* root;

		BinarySearchTree() {
			root = nullptr;
		}

		void insert(int key) {
			root = insertRec(root, key);
		}

		void deleteNode(int key) {
			root = deleteRec(root, key);
		}

		void inorder() {
			inorderRec(root);
			cout << endl;
		}

		void preorder() {
			if (root == nullptr) return;
			stack<TreeNode*> st;
			st.push(root);
			while (!st.empty()) {
				TreeNode* node = st.top();
				st.pop();
				cout << node->val << " ";
				if (node->right) st.push(node->right);
				if (node->left) st.push(node->left);
			}
			cout << endl;
		}

		void postorder() {
			if (root == nullptr) return;
			stack<TreeNode*> st1, st2;
			st1.push(root);
			while (!st1.empty()) {
				TreeNode* node = st1.top();
				st1.pop();
				st2.push(node);
				if (node->left) st1.push(node->left);
				if (node->right) st1.push(node->right);
			}
			while (!st2.empty()) {
				cout << st2.top()->val << " ";
				st2.pop();
			}
			cout << endl;
		}

		TreeNode* insertRec(TreeNode* node, int key) {
			if (node == nullptr)
				return new TreeNode(key);
			if (key < node->val)
				node->left = insertRec(node->left, key);
			else if (key > node->val)
				node->right = insertRec(node->right, key);
			return node;
		}

		TreeNode* deleteRec(TreeNode* node, int key) {
			if (node == nullptr)
				return node;
			if (key < node->val)
				node->left = deleteRec(node->left, key);
			else if (key > node->val)
				node->right = deleteRec(node->right, key);
			else {
				if (node->left == nullptr) {
					TreeNode* inorderSuccessor = node->right;
					delete node;
					return inorderSuccessor;
				} else if (node->right == nullptr) {
					TreeNode* inorderSuccessor = node->left;
					delete node;
					return inorderSuccessor;
				}
				TreeNode* inorderSuccessor = minValueNode(node->right);
				node->val = inorderSuccessor->val;
				node->right = deleteRec(node->right, inorderSuccessor->val);
			}
			return node;
		}

		TreeNode* minValueNode(TreeNode* node) {
			TreeNode* current = node;
			while (current && current->left != nullptr)
				current = current->left;
			return current;
		}

		void inorderRec(TreeNode* root) {
			if (root != nullptr) {
				inorderRec(root->left);
				cout << root->val << " ";
				inorderRec(root->right);
			}
		}
};

int main() {
	BinarySearchTree b;
	b.insert(50);
	b.insert(30);
	b.insert(20);
	b.insert(40);
	b.insert(70);
	b.insert(60);
	b.insert(80);

	cout << "Inorder: ";
	b.inorder();
	cout << "Preorder: ";
	b.preorder();
	cout << "Postorder: ";
	b.postorder();
}
