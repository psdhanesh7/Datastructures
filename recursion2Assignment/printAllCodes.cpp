// Print all Codes - String

// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. Just print them in different lines.
// Input format :

// A numeric string S

// Output Format :

// All possible codes in different lines

// Constraints :
// 1 <= Length of String S <= 10
// Sample Input:

// 1123

// Sample Output:

// aabc
// kbc
// alc
// aaw
// kw

#include <iostream>
#include <string.h>
using namespace std;

void printAllPossibleCodes(string input, string code = "") {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    if(input == "") {
    	cout << code << endl;
    	return;
    }

    char ch = (input[0] - '0' - 1) + 'a';
    printAllPossibleCodes(input.substr(1), ch + code);

    ch = ((input[0] - '0')*10 + (input[1] - '0') - 1) + 'a';
    if(ch >= 'a' && ch <= 'z') {
    	printAllPossibleCodes(input.substr(2), ch + code);
    }

}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
