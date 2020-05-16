#include <iostream>
using namespace std;

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
  {{2, 1, 4}, // Length of this subset is 2
  {2, 3, 2}}  // Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

// int subsetSumToK(int input[], int n, int output[][50], int k, int outputSize = 0) {
//     // Write your code here

//     if(k == 0) {
//         output[outputSize][0] = 0;
//         return outputSize + 1;
//     }

//     if(k < 0 || n == 0) {
//         return outputSize;
//     }

//     int size = subsetSumToK(input, n-1, output, k-input[n-1], outputSize);
//     for(int i = outputSize; i < outputSize + size; i++) {

//         int subsetSize = output[i][0];
//         output[i][subsetSize] = input[n-1];
//         output[i][0] = subsetSize + 1;
//     }

//     size  = subsetSumToK(input, n-1, output, k, outputSize + size);

//     return size;

// }

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here

    if(k == 0) {
        output[0][0] = 0;
        return 1;
    }

    if(k < 0 || n == 0) {
        return 0;
    }

    int size = subsetSumToK(input, n-1, output, k-input[n-1]);
    for(int i = 0; i < size; i++) {

        int subsetSize = output[i][0];
        output[i][subsetSize+1] = input[n-1];
        output[i][0] = subsetSize + 1;
    }

    int output2[100][50];
    int newSize  = subsetSumToK(input, n-1, output2, k);

    for(int i = 0; i < newSize; i++) {
        int subsetSize = output2[i][0];
        for(int j = 0; j <= subsetSize; j++ ) {
            output[i+size][j] = output2[i][j];
        }
    }

    return size + newSize;

}


int main() {
    int input[20],length, output[10000][50], k;
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for( int i = 0; i < size; i++) { 
        for( int j = 1; j <= output[i][0]; j++) { 
    	   cout << output[i][j] << " ";
        }
        cout << endl;
    }
}