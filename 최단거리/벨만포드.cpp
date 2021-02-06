#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define INF 987654321
typedef long long lld;
typedef pair<int, lld> pii;

int n, m, a, b, c;
vector<vector<pii>> g;
int dist[501];
//long long 
/*
1->2 -10000
2-> 1 -10000 6000개 30억
(500*600)*10^5 = 30*10^9
음의정수 계산시 시간초과 주의
*/

bool bell() {
	for (int k = 1; k < n; k++) {
		//edge 찾기
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < g[i].size(); j++) {
				pii next = g[i][j];
				int to = next.first;
				lld cost = next.second;
				if (dist[i] == INF) continue;
				if (dist[to] > dist[i] + cost) {
					dist[to] = dist[i] + cost;
				}
			}
		}
	}

	//check cycle 
	bool isCycle = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			pii next = g[i][j];
			int to = next.first;
			lld cost = next.second;
			if (dist[i] == INF) continue;
			if (dist[to] > dist[i] + cost) {
				isCycle = true;
				break;
			}
		}
		if (isCycle) break;
	}
	if (isCycle)return false;
	else return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i <= n; i++) dist[i] = INF;
	dist[1] = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
	}
	if (!bell()) { //cycle
		cout << -1 << '\n';
	}
	else {
		for (int i = 2; i <= n; i++) {
			if(dist[i]==INF) cout<< -1 << '\n';
			else  cout << dist[i] << '\n';
		}
	}
	return 0;
}