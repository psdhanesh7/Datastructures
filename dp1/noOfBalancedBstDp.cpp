#include <iostream>
using namespace std;
#include <cmath>

int binaryTreesOfHeightH(int h) {
    // Write your code here
	int *dp = new int[h+1];

	int mod = (int) pow(10, 9) + 7;
	
	dp[0] = 1;
	dp[1] = 1;

	for(int i = 2; i <= h; i++) {
		int x = dp[i-1];
		int y = dp[i-2];

		int temp1 = (int)(((long)x*x) % mod);
		int temp2 = (int)((2*(long)x*y) % mod);

		dp[i] = (temp1 + temp2) % mod;
	}

	int ans = dp[h];

	delete [] dp;
	return ans;
}


int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
	if(h == 1 || h == 0) {
		return 1;
	}
	
	int mod = (int) pow(10, 9) + 7;
	int x = balancedBTs(h-1);
	int y = balancedBTs(h-2);
	
	int temp1 = (int)(((long)x*x) % mod);
	int temp2 = (int)((2*(long)x*y) % mod);

	int ans = (temp1 + temp2) % mod;

	return ans;
}

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}

