void bubbleSort(int a[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; i++) {
			if (a[j] > a[i]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}