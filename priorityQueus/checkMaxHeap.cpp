#include <iostream>
using namespace std;

bool checkMaxHeap(int arr[], int n){
	
	for(int i = 0; i < n; i++) {
		int leftChildIndex = 2*i + 1;
		int rightChildIndex = 2*i + 2;

		if(leftChildIndex < n && arr[i] < arr[leftChildIndex]) {
			return false;
		}
		if(rightChildIndex < n && arr[i] < arr[rightChildIndex]) {
			return false;
		}
	}
	return true;
}

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
}

