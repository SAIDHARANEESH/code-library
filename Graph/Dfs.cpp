
vector<vector<int> adj(n);
vector<int> parent;
parent.assign(n, -1)
void dfs(int source) {
	visited[source] = true;
	cout << source << " ";
	for (auto v : adj[source]) {
		if (!visited[v]) {
			dfs(v);
			parent[v] = source;
		}
	}
	cout << '\n';
}