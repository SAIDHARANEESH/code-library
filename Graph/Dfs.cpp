


void dfs(int source) {
	visited[source] = true;

	cout << source << " ";
	for (auto v : adj[source]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
	cout << '\n';
}