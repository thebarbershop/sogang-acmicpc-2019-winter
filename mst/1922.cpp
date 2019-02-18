#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

typedef struct edge{
	int weight, u, v;
	bool operator<(struct edge &rhs) {
		return weight < rhs.weight;
	}
} edge;

std::vector<int> parent;
std::vector<int> rank;

int find(int x) {
	if (parent[x] == x) return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

void merge(int x, int y) {
	int root_x = find(x);
	int root_y = find(y);
	if (root_x != root_y) {
		if (rank[root_x] == rank[root_y]) {
			parent[root_y] = root_x;
			rank[root_x]++;
		}
		else if (rank[root_x] < rank[root_y]) {
			parent[root_y] = root_x;
		}
		else {
			parent[root_x] = root_y;
		}
	}
}

int main(void) {
	int n, m;
	std::vector<edge> edges;
	std::cin >> n >> m;
	while (m--) {
		int u, v, w;
		std::cin >> u >> v >> w;
		edges.push_back({ w, u-1, v-1 });
	}
	std::sort(edges.begin(), edges.end());

	parent.resize(n);
	rank.resize(n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 1;
	}

	int cost_of_MST = 0;
	for (auto edge : edges) {
		if (find(edge.u) != find(edge.v)) {
			cost_of_MST += edge.weight;
			merge(edge.u, edge.v);
		}
	}
	std::cout << cost_of_MST;

	return 0;
}