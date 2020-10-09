
struct FenwickTree {
	vector<int> bit;
	int n;
	/*
		n stores the size of fenwick tree
		bit stores the results of the fenwick tree
	*/
	FenwickTree(int n) {
		this->n = n;
		bit.assign(n, 0);
	}

	FenwickTree(vector<int> a) {
		for (size_t i = 0; i < a.size(); i++) {
			add(i, a[i]);
		}
	}
	//query to find sum between the range 1 and r
	int sum(int r) {
		int res = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			res += bit[r];
		return res;
	}
	
	//query to find sum between the range l and r
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	// building of fenwick tree
	void add(int index, int delta) {
		for (; index < n; index = index | (index + 1)) {
			bit[index] += delta;
		}
	}
};
