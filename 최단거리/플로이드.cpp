#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 10000000

int n, m, a, b, c;
vector<vector<int>> mat;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	//init
	mat.resize(n+1);
	for (int i = 1; i <= n; i++) {
		mat[i].push_back(0);
		for (int j = 1; j <= n; j++) {
			if (i == j) mat[i].push_back(0);
			else mat[i].push_back(INF);
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (mat[a][b] <= c) continue;
		mat[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {//내려가는칸
		vector<vector<int>> tmp = mat; //업데이트 되면서 값 바꿔버리면 안됨
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				mat[j][k] = min(tmp[j][k], tmp[j][i] + tmp[i][k]);
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == INF) cout << 0 << " ";
			else cout << mat[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}