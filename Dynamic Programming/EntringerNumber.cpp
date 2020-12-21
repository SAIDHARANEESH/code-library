int zigzag(int n, int k) {
	if (n == 0 && k == 0)
		return 1;
	if (k == 0)
		return 0;
	return zigzag(n, k - 1) + zigzag(n - 1, n - k);
}

int zigzag(int n, int k) {
	int dp[n + 1][k + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][i - j];
		}
	}
	return dp[n][k];
}
int main() {
	int n = 4, k = 3;
	cout << zigzag(n, k) << endl;
}