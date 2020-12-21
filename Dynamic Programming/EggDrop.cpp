int eggDrop(int n, int k) {
	if (k == 1 || k == 0)
		return k;
	if (n == 1)
		return k;
	int min = INT_MAX, x, res;
	for (int x = 1; x <= k; x++) {
		res = max(eggDrop(n - 1, x - 1), eggDrop(n, k - x));
		if (res < min)
			min = res;
	}
	return min + 1;
}

int eggDrop(int n, int k) {
	int dp[n + 1][k + 1];
	int res;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
		dp[i][0] = 0;
	}
	for (int j = 1; j <= k; j++) {
		dp[1][j] = j;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = INT_MAX;
			for (int x = 1; x <= j; x++) {
				res = 1 + max(dp[i - 1][x - 1]), dp[i][j - x];
				if (res < dp[i][j])
					dp[i][j] = res;
			}
		}
	}
	return dp[n][k];
}

int main() {
	int n = 2, k = 10;
	cout << "minimum number of trials in worst case with " << n << " eggs and " << k << " floors is " << eggDrop(n, k) << '\n';
	return 0;
}