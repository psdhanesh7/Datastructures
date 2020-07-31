#include <iostream>
#include <queue>
#include<climits>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

class TreeDetails {
	public :
		int height;
		bool isBst;
		int min;
		int max;
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

TreeDetails largestBstHelper(BinaryTreeNode<int>* root) {
	
	if(root == NULL) {
		TreeDetails ans;
		ans.height = 0;
		ans.isBst = true;
		ans.min = INT_MAX;
		ans.max = INT_MIN;

		return ans;
	}

	TreeDetails leftSubTree = largestBstHelper(root->left);
	TreeDetails rightSubTree = largestBstHelper(root->right);

	TreeDetails ans;
	if(rightSubTree.isBst && leftSubTree.isBst && root->data < rightSubTree.min && root->data > leftSubTree.max) {
		ans.isBst = true;
		ans.height = 1 + max(leftSubTree.height, rightSubTree.height);
		ans.min = min(leftSubTree.min, root->data);
		ans.max = max(rightSubTree.max, root->data);

		return ans;
	}

	ans.isBst = false;
	ans.height = max(leftSubTree.height, rightSubTree.height);
	ans.min = min(leftSubTree.min, root->data);
	ans.max = max(rightSubTree.max, root->data);

	return ans;

}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	TreeDetails ans = largestBstHelper(root);

	return ans.height;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
