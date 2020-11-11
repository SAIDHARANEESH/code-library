void selectionSort(int a[], int len) {
	int p = 0;
	for (int i = 0; i < len - 1; i++) {
		p = i;
		for (int j = i + 1; j < len; j++) {
			if (a[i] > a[j]) {
				p = j;
			}
		}
		int temp = a[i];
		a[i] = a[p];
		a[p] = temp;
	}
}