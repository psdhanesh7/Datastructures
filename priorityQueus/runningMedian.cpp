#include <iostream>
#include <queue>
using namespace std;

void findMedian(int arr[], int n){
	
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	maxHeap.push(arr[0]);
	cout << arr[0] << endl;

	for(int i = 1; i < n; i++) {
		if(arr[i] > maxHeap.top()) {
			minHeap.push(arr[i]);
			if(minHeap.size() - maxHeap.size() > 1) {
				int minElement = minHeap.top();
				minHeap.pop();
				maxHeap.push(minElement);
			}
		}
		else {
			maxHeap.push(arr[i]);
			if(maxHeap.size() - minHeap.size() > 1) {
				int maxElement = maxHeap.top();
				maxHeap.pop();
				minHeap.push(maxElement);
			}
		}
		
		int median;
		if((i+1) % 2 == 0) {
			int maxElement = maxHeap.top();
			int minElement = minHeap.top();
			
			median = (maxElement + minElement)/2;
		}
		else {
			median = minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
		}
		cout << median << endl;
	}
}

int main() {
    
    int n;
    cin >> n;

    int arr[n], i;
    for(i=0;i<n;i++) cin >> arr[i];

    findMedian(arr, n);
}
