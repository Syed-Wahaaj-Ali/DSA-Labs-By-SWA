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

class BinarySearchTree {
	public:
		TreeNode* root;

		BinarySearchTree() {
			root = nullptr;
		}

		void insert(int key) {
			root = insertRec(root, key);
		}

		int sumOfNodes() {
			return sumOfNodesRec(root);
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

		int sumOfNodesRec(TreeNode* node) {
			if (node == nullptr) return 0;
			int leftSum = sumOfNodesRec(node->left);
			int rightSum = sumOfNodesRec(node->right);
			return leftSum + rightSum + node->val;
		}
};

int main() {
	BinarySearchTree bst;
	bst.insert(10);
	bst.insert(30);
	bst.insert(20);
	bst.insert(5);
	bst.insert(15);
	bst.insert(35);
	bst.insert(25);

	cout << "Sum of all Nodes: " << bst.sumOfNodes() << endl;
	return 0;
}
