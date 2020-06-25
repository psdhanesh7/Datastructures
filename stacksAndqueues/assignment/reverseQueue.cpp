#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q) {
    // Write your code here
    if(q.empty()) {
        return;
    }

    int val = q.front();
    q.pop();
    reverseQueue(q);
    q.push(val);
}

int main() {
    queue<int> q;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	q.push(val);
    }
    reverseQueue(q);
    while(!q.empty()) {
    	cout << q.front() << " ";
    	q.pop();
    }
}
