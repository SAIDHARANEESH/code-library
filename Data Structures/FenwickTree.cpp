
struct FenwickTree {
	vector<int> bit;
	int n;

	FenwickTree(int n) {
		this->n = n;
		bit.assign(n, 0);
	}

	FenwickTree(vector<int> a) {
		for (size_t i = 0; i < a.size(); i++) {
			add(i, a[i]);
		}
	}

	int sum(int r) {
		int res = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			res += bit[r];
		return res;
	}
	
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int index, int delta) {
		for (; index < n; index = index | (index + 1)) {
			bit[index] += delta;
		}
	}
};
