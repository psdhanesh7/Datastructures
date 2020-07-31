#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
#include<unordered_set>

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
    	if(left) {
     		delete left;
    	}
	if(right) {
     		delete right;
    	}
    }
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

void traverseTree(BinaryTreeNode<int> *root, vector<int> &treeElements) {
	if(root == NULL) {
		return;
	}

	traverseTree(root->left, treeElements);
	treeElements.push_back(root->data);
	traverseTree(root->right, treeElements);
}

/*
void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	vector<int> treeElements;
	traverseTree(root, treeElements);

	sort(treeElements.begin(), treeElements.end());

	int i = 0;
	int j = treeElements.size() - 1;

	while(i < j) {
		int currSum = treeElements[i] + treeElements[j];
		if(currSum == sum) {
			cout << treeElements[i] << " " << treeElements[j] << endl;
			i++;
			j--;
		}
		else if (currSum < sum) {
			i++;
		}
		else {
			j--;
		}
	}
}

*/

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	vector<int> treeElements;
	traverseTree(root, treeElements);
	
	unordered_set<int> complements;
	for(int i = 0; i < treeElements.size(); i++) {
		int curr = treeElements[i];
		if(complements.count(curr) != 0) {
			cout << min(curr, sum-curr) << " " << max(curr, sum - curr) << endl;
		}
		else {
			complements.insert(sum - curr);
		}
	}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}
