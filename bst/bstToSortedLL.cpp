#include <iostream>
#include <queue>
#include<vector>

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

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
};

template <typename T>
class LL {
	public : 
		Node<T> *head;
		Node<T> *tail;

	LL() {
		this->head = NULL;
		this->tail = NULL;
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

/*
void traverseTree(BinaryTreeNode<int>* root, vector<int> &treeElements) {
	if(root == NULL) {
		return ;
	}

	traverseTree(root->left, treeElements);
	treeElements.push_back(root->data);
	traverseTree(root->right, treeElements);
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    
	vector<int> treeElements;
	traverseTree(root, treeElements);
	
	Node<int>* head = new Node<int>(treeElements[0]);
	Node<int>* curr = head;
	for(int i = 1; i < treeElements.size(); i++) {
		curr->next = new Node<int>(treeElements[i]);
		curr = curr->next;
	}

	return head;
}
*/

LL<int> traverseTree(BinaryTreeNode<int>* root) {
	
	if(root == NULL) {
		LL<int> ans;
		return ans;
	}
	
	LL<int> leftSubTree = traverseTree(root->left);
	LL<int> rightSubTree = traverseTree(root->right);
	
	LL<int> ans;
	Node<int>* curr = new Node<int>(root->data);
	if(leftSubTree.head == NULL) {
		ans.head = ans.tail = curr;
	}else {
		leftSubTree.tail->next = curr;
		ans.head = leftSubTree.head;
		ans.tail = curr;
	}

	if(rightSubTree.head != NULL) {
		ans.tail->next = rightSubTree.head;
		ans.tail = rightSubTree.tail;
	}

	return ans;
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
	
	LL<int> treeElements = traverseTree(root);
	return treeElements.head;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    } 
}
