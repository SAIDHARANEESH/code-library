void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int partition(int a[], int left, int right) {
	int pivot = right;
	int i = left - 1;
	for (int j = 0; j < right; j++) {
		if (a[j] < a[pivot]) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[pivot]);
	return i + 1;
}

void quickSort(int a[], int left, int right) {
	if (left < right) {
		int pivot = parition(a, left, mid);
	}
	quickSort(a, left, pivot);
	quickSort(a, pivot + 1, right);
}