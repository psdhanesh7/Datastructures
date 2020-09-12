#include <string>
#include "TrieNode.h"

class Trie {
	TrieNode *root;

	public:

	Trie() {
		root = new TrieNode('\0');
	}

	void insertWord(TrieNode *root, string word) {
		// Base case
		if(word.length() == 0) {
			root->isTerminal = true;
			return;
		}
		
		// Small calculation
		int index = word[0] - 'a';
		TrieNode *child;

		if(root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}

		insert(child, word.substr(1));
	}

	void insertWord(string word) {
		insertWord(root, word);
	}

	bool search(TrieNode *root, string word) {
		
		if(word.length() == 0) {
			return root->isTerminal;
		}

		int index = word[0] - 'a';
		if(root->children[index] == NULL) {
			return false;
		}

		bool ans = search(root->children[index], word.substr(1));

		return ans;
	}

	bool search(string word) {
		return search(root, word);
	}

	void removeWord(TrieNode *child, string word) {
		// Base case
		if(word.length() == 0) {
			root->isTerminal = false;
			return;
		}
		
		// Small calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			// Word not found
			return;
		}

		removeWord(child, word.substr(1));

		// Remove child if it is useless
		if(!child->isTerminal) {
			for(int i = 0; i < 26; i++) {
				if(child->children[i] != NULL) {
					return;
				}
			}

			delete child;
			root->children[index] = NULL;
		}
	}
};
