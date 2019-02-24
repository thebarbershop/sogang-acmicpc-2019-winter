#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using std::vector;
using std::queue;


int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> indegree(n);
    vector<vector<int>> adjacent_list(n);
	while(m--) {
		int u, v;
		scanf("%d%d", &u, &v);
        u--, v--;
		adjacent_list[u].push_back(v);
		indegree[v]++;
	}

	queue<int> q;
	for(int i = 0; i < n; i++) {
		if(!indegree[i]) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int current_vertex = q.front();
		q.pop();
		printf("%d ", current_vertex+1);
		for(auto &next_vertex: adjacent_list[current_vertex]) {
			indegree[next_vertex]--;
			if(!indegree[next_vertex]) {
				q.push(next_vertex);
			}
		}
	}
	printf("\n");
	return 0;
}