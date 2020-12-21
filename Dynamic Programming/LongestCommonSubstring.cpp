int lcs(char *x, char *y, int m, int n) {
	int lcsuff[m + 1][n + 1];
	int result = 0;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) 
				lcsuff[i][j] = 0;
			else if (x[i - 1] == y[j - 1]) {
				lcsuff[i][j] = lcsuff[i - 1][j - 1] + 1;
				result = max(result, lcsuff[i][j]);
			} else {
				lcsuff[i][j] = 0;
			}
		}
	}
	return result;
}

int main() {
	char x[] = "OldSite:GeeksforGeeks.org";
	char y[] = "NewSite:GeeksQuiz.com";

	int m = strlen(x);
	int n = strlen(y);
	cout << "length of longest common substring is " << lcs(x, y, m, n);
}