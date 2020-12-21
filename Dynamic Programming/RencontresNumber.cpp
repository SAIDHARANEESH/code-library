const int max = 100;
int binomialCoeff(int n, int k) {
	if (k == 0 || k == n)
		return 1;
	return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

int binomialCoeff(int C[][max], int n, int k) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {
			if (j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
}

int RencontresNumber(int n, int m) {
	if (n == 0 && m == 0)
		return 1;
	if (n == 1 && m == 0)
		return 0;
	if (m == 0)
		return (n - 1) * (RencontresNumber(n - 1, 0) + RencontresNumber(n - 2, 0));
	return binomialCoeff(n, m) * RencontresNumber(n - m, 0);
}

int RencontresNumber(int C[][max], int n, int m) {
	int dp[n + 1][m + 1] = { 0 };
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j <= i) {
				if (i == 0 && j == 0)
					dp[i][j] = 1;
				else if (i == 1 && j == 0)
					dp[i][j] = 0;
				else if (j == 0)
					dp[i][j] = (i - 1) * (dp[i - 1][0] + dp[i - 2][0]);
				else
					dp[i][j] = C[i][j] = dp[i - j][0];
			}
		}
	}
	return dp[n][m];
}
int main() {
	int n = 7, m = 2;
	int C[max][max];
	binomialCoeff(C, n, m);
	cout << RencontresNumber(C, n, m) << endl;
}