
// Return all codes - String

// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. And input string does not contain 0s.
// Input format :

// A numeric string

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
using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input == "") {
        output[0] = "";
        return 1;
    }

    string op1[10000];

    char ch = (input[0] - '0' - 1) + 'a';
    int size1 = getCodes(input.substr(1), op1);

    for(int i = 0; i < size1; i++) {
        output[i] = ch + op1[i];
    }

    ch = ((input[0] - '0')*10 + (input[1] - '0') - 1) + 'a';
    int size2 = 0;

    if(ch >= 'a' && ch <= 'z') {
        size2 = getCodes(input.substr(2), op1);

        for(int i = 0; i < size2; i++) {
            output[size1 + i] = ch + op1[i];
        }
    }
    
    return size1 + size2;
}



int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
