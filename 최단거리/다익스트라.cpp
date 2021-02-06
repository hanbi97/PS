#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;

#define INF 1000000000
typedef long long lld;
typedef pair<int, int> pii;

int n, e, k, u, v, w, dist[20001];
priority_queue <pii, vector<pii>, greater<pii>> pq;
vector<vector<pii>> graph;
void di(int start) {
	pq.push({ dist[start],start });
	while (!pq.empty()) {
		pii curr = pq.top(); pq.pop();
		int currVertex = curr.second; int currWeight = curr.first;
		if (currWeight > dist[currVertex]) continue;

		for (int i = 0; i < graph[curr.second].size(); i++) {
			pii next = graph[curr.second][i]; //¿¬°áÁ¡
			int nextVertex = next.first; int nextWeight = next.second;

			if (dist[nextVertex] > currWeight + nextWeight) {
				dist[nextVertex] = currWeight + nextWeight;
				pq.push({ currWeight + nextWeight , nextVertex });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> e >> k;
	graph.resize(n + 1);
	for (int i = 0; i < e; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}
	for (int i = 0; i <= n; i++) dist[i] = INF;
	dist[k] = 0;
	di(k);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}