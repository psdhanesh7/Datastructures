#include<iostream>
#include<unordered_set>
#include<cstring>
using namespace std;

char* uniqueChar(char *str){
    // Write your code here
	unordered_set<char> s;
	
	int length = strlen(str);
	char* uniqueString = new char[length + 1];

	int j = 0;
	for(int i = 0; i < length; i++) {
		if(s.count(str[i]) == 0) {
			uniqueString[j] = str[i];
			s.insert(str[i]);
			j++;
		}
	}
	uniqueString[j] = '\0';

	return uniqueString;
}

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}

