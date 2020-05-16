// Print Subsets of Array
// Send Feedback
// Given an integer array (of length n), find and print all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print the subsets in different lines.
// Input format :

// Line 1 : Integer n, Size of array
// Line 2 : Array elements (separated by space)

// Constraints :
// 1 <= n <= 15
// Sample Input:

// 3
// 15 20 12

// Sample Output:

// [] (this just represents an empty array, don't worry about the square brackets)
// 12 
// 20 
// 20 12 
// 15 
// 15 12 
// 15 20 
// 15 20 12 

#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[], int size, int subset[], int subSize) {
	// Write your code here
    if(size == 0) {
        for(int i = 0; i < subSize; i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
        return ;
    }
    
    printSubsetsOfArray(input+1, size-1, subset, subSize);
    
    subset[subSize++] = input[0];
    printSubsetsOfArray(input+1, size-1, subset, subSize);
    
}

void printSubsetsOfArray(int input[], int size) {
    
    int *subset = new int[size];
    
    printSubsetsOfArray(input, size, subset, 0);

    delete [] subset;
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}


