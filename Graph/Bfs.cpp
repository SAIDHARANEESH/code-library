
vector<vector<int> adj(n);
vector<int> parent;
parent.assign(n, -1);
void bfs(int source) {
	queue<int> q;
	q.push(source);
	while(!q.empty()) {
		int v = q.front();
		visited[v] = true;
		q.pop();
		cout << source << " ";
		for (auto v : adj[source]) {
			if (!visited[v]) {
				cout << v << " ";
				visited[v] = true;
				q.push(v);
				parent[v] = source];
			}
		}
		cout << '\n';
	}
}