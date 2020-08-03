#include <bits/stdc++.h>
using namespace std;

void pairSum(int *input, int n) {
    //Write your code here
	unordered_map<int, int> frequency;
	for(int i = 0; i < n; i++) {
		int complement = -1 * input[i];
		for(int j = 0; j < frequency[complement]; j++) {
			cout << min(input[i], complement) << " " << max(input[i], complement) << endl;
		}
		frequency[input[i]]++;
	}
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	pairSum(arr, n);

	delete[] arr;

	return 0;
}
