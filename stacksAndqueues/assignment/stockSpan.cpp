#include <iostream>
#include <stack>
using namespace std;

int* stockSpan(int *price, int size) {
    // Write your code here
    stack<int> s;
    int* span = new int[size];

    s.push(0);
    span[0] = 1;

    for(int i = 1; i < size; i++) {
        if(price[i] <= price[s.top()]) {
            span[i] = 1;
            s.push(i);
        }
        else {
            while(!s.empty() && price[s.top()] < price[i]) {
                s.pop();
            }
            if(s.empty()) {
                span[i] = i+1;
            }
            else {
                span[i] = i - s.top();
            }
            s.push(i);
        }
    }

    return span;

}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }

    delete [] output;
    return 0;
}
