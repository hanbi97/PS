#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll INF = 1e18;
int n, mat[16][16], total;
ll dp[16][(1 << 16) + 1];

ll dfs(int before, int curr) {
	if (before == total) return mat[curr][0] == 0 ? INF : mat[curr][0];

	if (dp[curr][before] != INF) return dp[curr][before];//방문한적있음

	for (int i = 0; i < n; i++) {
		if (mat[curr][i] == 0) continue; //길 없음
		if (before & (1<<i)) continue;//이미 지나간길
		dp[curr][before] = min(dp[curr][before], dfs((before | (1 << i)), i) + mat[curr][i]);
	}
	return dp[curr][before];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	total = (1 << n) - 1;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < total; j++) {
			dp[i][j] = INF;
		}
	}
	cout << dfs(1, 0);
	return 0;
}