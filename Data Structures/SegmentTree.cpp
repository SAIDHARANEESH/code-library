void build(int v, int l, int r, int a[]) {
	if (l == r) { 
		t[v] = a[l];
	} else {
		int mid = (l + r) >> 1;
		build(2 * v + 1, l, mid, a);
		build(2 * v + 2, mid + 1, r, a);
		t[v] = t[2 * v + 1] + t[2 * v + 2];
	}
}

void update(int v, int l, int r, int pos, int val) {
	if (l == r) {
		t[v] = val;
	} else {
		int mid = (l + r) >> 1;
		if (pos <= mid) {
			update(2 * v + 1, l, mid, pos, val);
		} else {
			update(2 * v + 2, mid + 1, r, pos, val);
		}
		t[v] = t[2 * v + 1] + t[2 * v + 2];
	}
}

