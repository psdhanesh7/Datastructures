#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <vector>

class TrieNode
{
	public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

	public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    // For user
    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }

	bool reverseSearch(TrieNode *root, string word) {
		if(word.length() == 0) {
			return root->isTerminal;
		}

		if(root->isTerminal && word.length() == 1) {
			return true;
		}

		int index = word[word.length() - 1] - 'a';
		TrieNode *child;

		if(root->children[index] == NULL) {
			return false;
		}
		
		child = root->children[index];
		return reverseSearch(child, word.substr(0, word.length()-1));
	}

    /*..................... Palindrome Pair................... */
    

    bool isPalindromePair(vector<string> words)
    {
		//Write your code here
		for(int i = 0; i < words.size(); i++) {
			add(words[i]);
		}
		
		bool isPalindrome = false;
		for(int i = 0; i < words.size(); i++) {
			isPalindrome = reverseSearch(root, words[i]) || reverseSearch(root, words[i].substr(0, words[i].length()-1));
			if(isPalindrome) {
				break;
			}
		}

		return isPalindrome;
    }

};
int main()
{
	Trie t;
	int n;
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> words[i];
	}
	bool ans = t.isPalindromePair(words);

	if (ans)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}
