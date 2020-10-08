



void build(int a[], int left, int right, int v) {
	if (left == right) {
		t[v] = a[left];
	}
	else {
		int mid = (left + right) >> 1;
		build(a, left, mid, 2 * v + 1);
		build(a, mid + 1, right, 2 * v + 2);
	}
}

void update(int v, int left, int right, int pos, int value) {
	if (left == right) {
		t[v] = value;
	}
	else {
		int mid = (left + right) >> 1;
		if (pos <= mid) {
			update(2 * v + 1, left, mid, pos, value);
		}
		else {
			update(2 * v + 2, mid + 1, right, pos, value);
		}
		t[v] = t[2 * v + 1] + t[2 * v + 2];
	}
}

int sum(int v, int left, int right, int l, int r) {
	if (l > r) {
		return 0;
	}
	if (l == left && r == right) {
		return t[v];
	}
	int mid = (left + right) >> 1;
	return sum(2 * v + 1, left, mid, l, min(r, mid)) + sum(2 * v + 2, mid + 1, right, max(l, mid + 1), r);
}