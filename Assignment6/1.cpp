#include<bits/stdc++.h>

using namespace std;
int n;
int c, x, y, z;
int dp[810][200][100], cal[810][200][100];

// Use dynamic programming to solve, record the (sum,n1,n2,n3) state
// sum is the number of the cola, and the later represent 1,5,10 coins number.
int dfs(int num, int n1, int n2, int n3) {
	// record the result to prevent calculate twice
    int &sum = dp[n1][n2][n3];              //record the answer
    int &flag = cal[n1][n2][n3];			//record whether we calculate the answer
    // Base case
	if (flag == 1) 
		return sum;
    else 
		if (num == 0) {
			flag = 1;
			sum = 0;
			return sum;
    	}
    else { // Find the optimal transition
		sum = 1e9 + 7;
		flag = 1;
		// Case1: 10 = 8 + 1 * 2
		if (n3 >= 1) sum = min(sum, dfs(num - 1, n1 + 2, n2, n3 - 1) + 1);
		// Case2: 10 + 1 * 3 = 8 + 5
		if (n3 >= 1 && n1 >= 3) sum = min(sum, dfs(num - 1, n1 - 3, n2 + 1, n3 - 1) + 4);
		// Case3: 5 * 2 = 8 + 1 * 2
		if (n2 >= 2) sum = min(sum, dfs(num - 1, n1 + 2, n2 - 2, n3) + 2);
		// Case4: 5 + 1 * 3 = 8
		if (n2 >= 1 && n1 >= 3) sum = min(sum, dfs(num - 1, n1 - 3, n2 - 1, n3) + 4);
		// Case5: 1 * 8 = 8
		if (n1 >= 8) sum = min(sum, dfs(num - 1, n1 - 8, n2, n3) + 8);
		return sum;
    }
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> c >> x >> y >> z;
		memset(cal, 0, sizeof(cal));	
		int ans = dfs(c, x, y, z);
		cout << ans << endl;
	}
		
}
