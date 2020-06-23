#include <iostream>
#include <stack>
using namespace std;

bool isOpeningParenthesis(char c) {
	return c == '[' || c == '{' || c == '(';
}

bool isClosingParenthesis(char c) {
	return c == ']' || c == '}' || c == ')';
}

char openingParenthesis(char c) {

	switch(c) {
		case '}' : return '{';
		case ']' : return '[';
		case ')' : return '(';
		default : return '\0';
	}
}

bool checkBalanced(char *exp) {
	// Write your code here
	stack<char> s;

	for(int i = 0; exp[i] != '\0'; i++) {
		if(isOpeningParenthesis(exp[i])) {
			s.push(exp[i]);
		}
		else if(isClosingParenthesis(exp[i])) {
			if(s.empty()|| s.top() != openingParenthesis(exp[i])) {
				return false;
			}

			s.pop();
		}
	}

	if(s.empty()) {
		return true;
	}

	return false;

}

int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
// { a + [ b+ (c + d)] + (e + f) }
