#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

void intersection(int input1[], int input2[], int size1, int size2) {
	
	unordered_map<int, int> m1, m2;

	for(int i = 0; i < size1; i++) {
		m1[input1[i]]++;
	}
	for(int i = 0; i < size2; i++) {
		m2[input2[i]]++;
	}

	unordered_map<int, int> :: iterator it;
	for(it = m1.begin(); it != m1.end(); it++) {
		int key = it->first;
		int frequency = min(m1[key], m2[key]);
		for(int i = 0; i < frequency; i++) {
			cout << key << endl;
		}
	}
}

int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];	
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];	
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	
	
	intersection(input1,input2,size1,size2);

		
	return 0;
}

