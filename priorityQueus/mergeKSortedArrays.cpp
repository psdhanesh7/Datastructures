#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ValueDetails {
	public :

	int value;
	int vectorNo;
	int index;

	ValueDetails(int value, int vectorNo, int index) {
		
		this->value = value;
		this->vectorNo = vectorNo;
		this->index = index;
	}
};

class Compare {
	public :

	bool operator() (ValueDetails a, ValueDetails b) {
		return a.value > b.value;
	}
};
	
vector<int> mergeKSortedArrays(vector<vector<int>*> input){ 
	
	priority_queue<ValueDetails, vector<ValueDetails>, Compare> pq;
	for(int i = 0; i < input.size(); i++) {
		ValueDetails currValue(input[i]->at(0), i, 0);
		pq.push(currValue);
	}

	vector<int> sortedArray;

	while(!pq.empty()) {
		ValueDetails currentValue = pq.top();
		pq.pop();

		sortedArray.push_back(currentValue.value);
		if(currentValue.index < input[currentValue.vectorNo]->size() - 1) {
			ValueDetails nextValue(input[currentValue.vectorNo]->at(currentValue.index + 1), currentValue.vectorNo, currentValue.index + 1);
			pq.push(nextValue);
		}
	}

	return sortedArray;
}

int main() {
	
	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
	
	
	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	for(int i = 0; i < input.size(); i++) {
		delete input[i];
	}

	return 0;
}

