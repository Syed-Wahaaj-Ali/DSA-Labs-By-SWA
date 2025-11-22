#include <iostream>
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
		TreeNode(int v) {
			val = v;
			left = nullptr;
			right = nullptr;
		}
};

class BST {
	public:
		TreeNode* root;

		BST() {
			root = nullptr;
		}

		void insert(int key) {
			root = insertRec(root, key);
		}

		int getMinDiff() {
			prev = -1;
			minDiff = INT_MAX;
			inOrderMinDiff(root);
			return minDiff;
		}

	private:
		TreeNode* insertRec(TreeNode* node, int key) {
			if (node == nullptr)
				return new TreeNode(key);
			if (key < node->val)
				node->left = insertRec(node->left, key);
			else if (key > node->val)
				node->right = insertRec(node->right, key);
			return node;
		}

		int prev;
		int minDiff;

		void inOrderMinDiff(TreeNode* node) {
			if (node == nullptr) return;

			inOrderMinDiff(node->left);

			if (prev != -1) {
				int diff = node->val - prev;
				if (diff < minDiff) minDiff = diff;
			}
			prev = node->val;

			inOrderMinDiff(node->right);
		}
};

int main() {
	BST b;
	b.insert(4);
	b.insert(2);
	b.insert(6);
	b.insert(1);
	b.insert(3);
	cout << "Minimum difference between any two Nodes: " << b.getMinDiff() << endl;
	return 0;
}
