// Print Permutations - String

// Given a string, find and print all the possible permutations of the input string.
// Note : The order of permutations are not important. Just print them in different lines.
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

void printPermutations(string input, string permutation = ""){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input == "") {
        cout << permutation << endl;
        return ;
    }
    
    for(int i = 0; i < input.length(); i++) {
        string newInput = input.substr(0, i) + input.substr(i+1);
        printPermutations(newInput, permutation + input[i]);

    }
}


int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
