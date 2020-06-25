#include <iostream>
#include <stack>
using namespace std;

bool checkRedundantBrackets(char *input) {
	// Write your code here
	stack<char> s;
	int prevDist = 0;
	for(int i = 0; input[i] != '\0'; i++) {
		if(input[i] != ')') {
			s.push(input[i]);
		}
		else {
			int usefulChar = 0;
			while(s.top() != '(') {
				s.pop();
				usefulChar++;
			}
			s.pop();

			if(usefulChar == 0) {
				return true;
			}
		}
	}

	return false;
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }

}
