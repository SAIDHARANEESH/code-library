int n;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;

void dfs(int v) {
	used[v] = true;
	comp.push_back(v);
	for (size_t i = 0; i < (in ) g[v].size(); i++) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
}

void find_comps() {
	for (inti = 0; i < n; i++) {
		used[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			comp.clear();
			dfs(i);
			cout << "component:";
			for (size_t j = 0; j < comp.size(); j++) {
				cout << " " << comp[j];
			}
			cout << endl;
		}
	}
}