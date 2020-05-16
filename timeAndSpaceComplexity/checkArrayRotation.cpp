// Check Array Rotation

// Given an integer array, which is sorted (in increasing order) and has been rotated by some number k in clockwise direction. Find and return the k.
// Input format :

// Line 1 : Integer n (Array Size)
// Line 2 : Array elements (separated by space)

// Output Format :

// Integer k

// Constraints :

// 0 <= n <= 10^7

// Sample Input 1:

// 6
// 5 6 1 2 3 4

// Sample Output 1:

// 2

// Sample Input 2:

// 5
// 3 6 8 9 10

// Sample Output 2:

// 0


#include <iostream>
using namespace std;

int FindSortedArrayRotation(int ar[], int size) {
    
    for(int i = 1; i < size; i++) {
        if(ar[i] < ar[i-1]) {
            return i;
        }
    }
    
    return 0;
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindSortedArrayRotation(input,size);
	
	return 0;

}

