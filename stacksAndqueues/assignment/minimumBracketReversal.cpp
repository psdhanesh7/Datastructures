#include <iostream>
#include <stack>
using namespace std;

int countBracketReversals(char input[]){
	// Write your code here
	stack<char> s;
	int minReversal = 0;
	for(int i = 0; input[i] != '\0'; i++) {
		if(input[i] == '{') {
			s.push(input[i]);
		}
		else if (input[i] == '}' && s.empty()) {
			minReversal++;
			s.push('{');
		}
		else {
			s.pop();
		}
	}

	if(s.size() % 2 != 0) {
		return -1;
	}

	minReversal += s.size()/2;

	return minReversal;
}


int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}