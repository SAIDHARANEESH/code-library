void dijkstra(int source) {
	vector<int> precedor, distance;
	precedor.assign(n, -1);
	distance.assign(n, INF);
	vector<bool> specialSet(n, false);
	distance[source] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!specialSet(source) && (v == -1 || d[j] < d[v])) {
				v = j;
			}
		}
		if (distance[v] == INF) break;
		specialSet[v] = true;
		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;
			if (distance[v] + len < distance[to]) {
				distance[to] = distance[v] + len;
				precedor[to] = v;
			}
		}
	}
}