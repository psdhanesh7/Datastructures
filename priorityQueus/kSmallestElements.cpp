#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> kSmallest(int *input, int n, int k) {
	// Write your code here
	priority_queue<int> pq;
	for(int i = 0; i < k; i++) {
		pq.push(input[i]);
	}

	for(int i = k; i < n; i++) {
		pq.push(input[i]);
		pq.pop();
	}

	vector<int> kSmallestElements;
	while(!pq.empty()) {
		kSmallestElements.push_back(pq.top());
		pq.pop();
	}

	return kSmallestElements;
}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	vector<int> output = kSmallest(input, n, k);
	for(int i = 0; i < output.size(); i++){
		cout << output[i] << endl;
	}
}

