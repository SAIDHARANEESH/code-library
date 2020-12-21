const int inf = 99999;
const int v = 4;
void floydWarshall(int graph[][V]) {
	/*
		dist will be output matrix
		that stores the shortest path between
		every pair of vertices
	*/
	int dist[v][v], i, j, k;
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			dist[i][j] = graph[i][j];

	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][i];
			}
		}
	}
	printSolution(dist);
}

void printSolution(int dist[][V]) {
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (dist[i][j] == inf)
				cout << "inf" << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	
}

//Driver method
int main() {
	int graph[v][v] = { {0, 5, inf, 10},
											{inf, 0, 3, inf},
											{inf, inf, 0, 1},
											{inf, inf, inf, 0}
										};
	floydWarshall(graph);
	return 0;
}