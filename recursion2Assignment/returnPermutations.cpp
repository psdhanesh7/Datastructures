// Return Permutations - String

// Given a string S, find and return all the possible permutations of the input string.
// Note 1 : The order of permutations is not important.
// Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
// Input Format :

// String S

// Output Format :

// All permutations (in different lines)

// Sample Input :

// abc

// Sample Output :

// abc
// acb
// bac
// bca
// cab
// cba

#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input == "") {
        output[0] = "";
        return 1;
    }
    
    int size = 0;
    string op[10000];
    for(int i = 0; i < input.length(); i++) {
    	
        string newInput = input.substr(0, i) + input.substr(i+1);
        int newSize = returnPermutations(newInput, op);
        
        for(int j = 0; j < newSize; j++) {
            output[size++] = input[i] + op[j];
        }
    }
    
    return size;
    
}


int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

