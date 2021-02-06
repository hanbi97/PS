#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define MAX 100
#define G 0
typedef long long lld;
typedef pair<int, int> pii;
int t, n, m, cards[1001], dp[1001][1001];

int dfs(int turn, int s, int e) {
	if (s == e) {
		if (turn == G) return cards[s];
		else return 0;
	}
	if (dp[s][e] != -1) return dp[s][e];
	if (turn == G) {
		dp[s][e] = max(dfs(!turn, s + 1, e)+cards[s], dfs(!turn, s, e - 1)+cards[e]);
	}
	else {
		dp[s][e] = min(dfs(!turn, s + 1, e), dfs(!turn, s, e - 1));
	}
	return dp[s][e];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		memset(cards, 0, sizeof(cards));
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) cin >> cards[i];
		cout << dfs(G,0,n-1)<< '\n';
	}
	return 0;
}