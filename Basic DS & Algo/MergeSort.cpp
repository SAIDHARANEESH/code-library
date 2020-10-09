void merge(int a[], int left, int mid, int right) {
	int n1 = mid - left + 1, n2 = right - mid + 1;
	int first[n1], second[n2];
	for (int i = 0; i < n1; i++) {
		first[i] = a[left + i + 1];
	}
	for (int i = 0; i < n2; i++) {
		second[i] = a[mid + i];
	}
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (first[i] < second[j]) {
			a[k] = first[i];
			i++;
		}
		else {
			a[k] = second[j];
			j++;
		}
		k++;
	}
	for (; i < n1; i++) {
		a[k] = first[i];
		k++;
	}
	for (; j < n2; j++) {
		a[k] = second[j];
	}
}

void mergeSort(int a[], int left, int right) {
	if (left < right) {
		int mid = (left + right) >> 1;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}