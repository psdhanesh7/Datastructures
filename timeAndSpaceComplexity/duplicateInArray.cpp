// Duplicate in array

// Given an array of integers of size n which contains numbers from 0 to n - 2. Each number is present at least once. That is, if n = 5, numbers from 0 to 3 is present in the given array at least once and one number is present twice. You need to find and return that duplicate number present in the array.
// Assume, duplicate number is always present in the array.
// Input format :

// Line 1 : Size of input array
// Line 2 : Array elements (separated by space)

// Output Format :

// Duplicate element

// Constraints :
// 1 <= n <= 10^6
// Sample Input:

// 9
// 0 7 2 5 4 7 1 3 6

// Sample Output:

// 7

#include <iostream>
using namespace std;

int DuplicateNumber(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int sum1 = ((size-2) * (size-1))/2;
    int sum2 = 0;
    
    for(int i = 0; i < size; i++) {
        sum2 += arr[i];
    }
    
    return sum2 - sum1;
}

int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout << DuplicateNumber(input, size);	
	
	delete [] input;

	return 0;
}

