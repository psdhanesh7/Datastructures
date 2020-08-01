#include <vector>
#include <climits>

class PriorityQueue {
	
	vector<int> pq;

	public:

	bool isEmpty() {
		return pq.size() == 0;
	}

	int getSize() {
		return pq.size();
	}

	int getMax() {
		return pq[0];
	}

	void insert(int element) {
		
		pq.push_back(element);

		int childIndex = pq.size() - 1;
		while(childIndex > 0) {
			int parentIndex = (childIndex - 1)/2;
			if(pq[childIndex] > pq[parentIndex]) {
				swap(pq[childIndex], pq[parentIndex]);
			}
			else {
				break;
			}

			childIndex = parentIndex;
		}
	}

	int removeMax() {

		int maxElement = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		int parentIndex = 0;
		int leftChildIndex = 1;
		int rightChildIndex = 2;

		while(leftChildIndex < pq.size()) {
			
			int maxIndex = parentIndex;
			if(pq[maxIndex] < pq[leftChildIndex]) {
				maxIndex = leftChildIndex;
			}
			if(rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex]) {
				maxIndex = rightChildIndex;
			}
			if(maxIndex == parentIndex) {
				break;
			}

			swap(pq[parentIndex], pq[maxIndex]);

			parentIndex = maxIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndex = 2 * parentIndex + 2;
		}
		return maxElement;
	}
};
