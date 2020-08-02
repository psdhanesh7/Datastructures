#include <iostream>
using namespace std;

void heapify(int heap[], int size) {
	
	int childIndex = size - 1;
	while(childIndex > 0) {

		int parentIndex = (childIndex - 1)/2;
		if(heap[parentIndex] > heap[childIndex]) {
			swap(heap[parentIndex], heap[childIndex]);
		}
		else {
			break;
		}

		childIndex = parentIndex;
	}
}

void downHeapify(int heap[], int size) {
	
	int parentIndex = 0;
	int leftChildIndex = 1;
	int rightChildIndex = 2;

	while(leftChildIndex < size) {
		
		int minIndex = parentIndex;
		if(heap[leftChildIndex] < heap[minIndex]) {
			minIndex = leftChildIndex;
		}
		if(rightChildIndex < size && heap[rightChildIndex] < heap[minIndex]) {
			minIndex = rightChildIndex;
		}
		
		if(minIndex == parentIndex) {
			break;
		}
		swap(heap[parentIndex], heap[minIndex]);
		
		parentIndex = minIndex;
		leftChildIndex = 2 * parentIndex + 1;
		rightChildIndex = 2 * parentIndex + 2;
	}
}

void inplaceHeapSort(int input[], int n){

	for(int i = 1; i < n; i++) {
		heapify(input, i+1);
	}

	for(int i = 0; i < n; i++) {
		swap(input[0], input[n-1-i]);
		downHeapify(input, n-1-i);
	}		
}

int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";
	
	delete [] input;
	return 0;
}

