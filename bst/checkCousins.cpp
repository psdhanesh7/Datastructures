#include <iostream>
#include <queue>

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

class ParentDetails {
	public :
		int level;
		BinaryTreeNode<int>* parent;
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}
/*
ParentDetails getParentDetails(BinaryTreeNode<int>* root, int element) {
	
	if(root == NULL) {
		ParentDetails ans;
		ans.level = -1;
		ans.parent = NULL;

		return ans;
	}

	if(root->data == element) {
		ParentDetails ans;
		ans.level = 0;
		ans.parent = NULL;

		return ans;
	}

	if(root->left != NULL) {
		if(root->left->data == element) {
			
		}
	}
	

}


bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
	if(root == NULL) {
		return false;
	}
	
	ParentDetails first = getParentDetails(root, p);
	ParentDetails second = getParentDetails(root, q);

	if(first.level == second.level && first.parent != second.parent) {
		return true;
	}
	return false;

}
*/

bool getPath(BinaryTreeNode<int>* root, int p, vector<int>& path) {
	
	if(root == NULL) {
		return false;
	}

	if(root->data == p) {
		path.push_back(root->data);
		return true;
	}

	bool left = getPath(root->left, p, path);
	bool right = getPath(root->right, p, path);

	if(left || right) {
		path.push_back(root->data);
		return true;
	}

	return false;


}		

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
	
	vector<int> path1, path2;	
	getPath(root, p, path1);
	getPath(root, q, path2);

	int level1 = path1.size();
	int level2 = path2.size();
/*	
	for(int i = 0; i < path1.size(); i++) {
		cout << path1[i] << " " ;
	}
	cout << endl;

	for(int i = 0; i < path2.size(); i++) {
		cout << path2[i] << " " ;
	}
	cout << endl;
*/
	if(level1 == level2 && path1[1] != path2[1]) {
		return true;
	}

	return false;
}	

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}
