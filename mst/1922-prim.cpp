#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

typedef struct edge {
	int weight, destination;
	bool operator<(const struct edge &rhs) const{
		return weight > rhs.weight;
	}
}edge;

int main(void) {
	int n, m;
	std::vector<std::vector<edge>> adjacent_list;
	std::cin >> n >> m;

	adjacent_list.resize(n);
	int longest_edge = 0;
	while (m--) {
		int u, v, w;
		std::cin >> u >> v >> w;
		u--;
		v--;
		adjacent_list[u].push_back({ w, v });
		adjacent_list[v].push_back({ w, u });
		longest_edge = std::max(longest_edge, w);
	}
	
	std::priority_queue<edge> pq;
	std::vector<bool> is_in_MST(n, false);
	std::vector<int> parent(n);
	std::vector<int> key(n, longest_edge+1);
	key[0] = 0;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		int vertex = pq.top().destination;
		pq.pop();
		if (is_in_MST[vertex]) continue;
		is_in_MST[vertex] = true;
		for(auto &neighbor: adjacent_list[vertex]) {
			if(neighbor.weight < key[neighbor.destination]
				&& !is_in_MST[neighbor.destination])
			{
				key[neighbor.destination] = neighbor.weight;
				parent[neighbor.destination] = vertex;
				pq.push({ neighbor.weight, neighbor.destination });
			}
		}
	}

	int cost_of_MST = 0;
	for (auto &elem : key) {
		cost_of_MST += elem;
	}
	std::cout << cost_of_MST;
	
	return 0;
}