int lps(char *str) {
	int n = strlen(str);
	int i, j, cl;
	int l[n][n];
	for (int i = 0; i < n; i++)
		l[i][j] = 1;
	for (cl = 2; cl <= n; cl++) {
		for (i = 0; i < n - cl + 1; i++) {
			j = i + cl - 1;
			if (str[i] == str[j] && cl == 2)
				l[i][j] = 2;
			else if (str[i] == str[j])
				l[i][j] = l[i + 1][j - 1] + 2;
			else
				l[i][j] = max(l[i][j - 1], l[i + 1][j]);
		}
	}
	return l[0][n - 1];
}

int main() {
	char seq[] = "GEEKS FOR GEEKS";
	int n = strlen(seq);
	cout << "The length of the LPS is " << lps(seq);
	return 0;
}