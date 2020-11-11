bool linearSearch(int a[], int value, int len) {
	for (int i = 0; i < len; i++) {
		if (a[i] == value) {
			return true;
		}
	}
	return false;
}