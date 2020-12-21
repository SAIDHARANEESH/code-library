struct Edge {
	int src, dest, weight;
};

struct Graph {
	int v, e;
	struct Edge* edge;
};

struct Graph* createGraph(int v, int e) {
	struct Graph8* graph = new Graph;
	graph->v = v;
	graph->e = e;
	graph->edge = new Edge[e];
	return graph;
}

void BellmanFord(struct Graph* graph, int src) {
	int v = graph->v;
	int e = graph->e;
	int dist[v];
	for (int i = 0; i < v; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < e; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}
	for (int i = 0; i < e; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dist;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			cout << "graph contains negative weight cycle";
			return;
		}
	}
	printArr(dist, v);
}

void printArr(int dist[], int n) {
	cout << "vertex distance from source\n";
	for (int i = 0; i < n; i++)
		cout << i << " \t\t " << dist[i] << '\n';
}

int main() {
	int v = 5;
	int e = 8;
	struct Graph* graph = createGraph(v, e);

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;

	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;

	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;

	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;

	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;

	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;

	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 1;

	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3; 

	BellmanFord(graph, 0);
}