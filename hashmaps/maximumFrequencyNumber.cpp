#include<iostream>
#include<unordered_map>
using namespace std;
 	
int highestFrequency(int *input, int n){	 
	
	unordered_map<int, int> frequency;

	for(int i = 0; i < n; i++) {
		frequency[input[i]]++;
	}
	
	int mostFrequentElement = input[0];
	for(int i = 1; i < n; i++) {
		mostFrequentElement = frequency[input[i]] > frequency[mostFrequentElement] ? input[i] : mostFrequentElement;
	}

	return mostFrequentElement;
}

int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}



