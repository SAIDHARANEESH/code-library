int maxRevenue(int m, int x[], int revenue[], int n, int t) {
	int maxRev[m + 1];
	memset(maxRev, 0, sizeof(maxRev));
	int nxtbb = 0;
	for (int i = 1; i <= m; i++) {
		if (nxtbb < n) {
			if (x[nxtbb] != i)
				maxRev[i] = maxRev[i - 1];
			else {
				if (i <= t)
					maxRev[i] = max(maxRev[i - 1], revenue[nxtbb]);
				else 
					maxRev[i] = max(maxRev[i - t - 1] + revenue[nxtbb], maxRev[i - 1]);
				nxtbb++;
			}
		} else {
			maxRev[i] = maxRev[i - 1];
		}
	}
	return maxRev[m];
}

int main() {
	int m = 20;
	int x[] = {6, 7, 12, 13, 14};
	int revenue[] = {5, 6, 5, 3, 1};
	int n = sizeof(x) / sizeof(x[0]);
	int t = 5;
	cout << maxRevenue(m, x, revenue, n, t) << endl;
	return 0;
}