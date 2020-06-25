#include <iostream>
#include <stack>
using namespace std;

void swap(stack<int> &s1, stack<int> &s2) {

    if(s1.empty()) {
        return;
    }

    int val1 = s1.top();
    s1.pop();

    int val2 = s2.top();
    s2.pop();

    swap(s1, s2);

    s1.push(val2);
    s2.push(val1);
}

void reverseStack(stack<int> &input, stack<int> &extra) {
    // Write your code here
    int size = input.size();

    for(int i = 0; i < size/2; i++) {
        int value = input.top();
        extra.push(value);
        input.pop();
    }

    int middleValue;
    if(size%2 != 0) {
        middleValue = input.top();
        input.pop();
    }

    swap(input, extra);

    if(size%2 != 0) {
        input.push(middleValue);
    }

    while(!extra.empty()) {
        int value = extra.top();
        input.push(value);
        extra.pop();
    }


}

int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}
