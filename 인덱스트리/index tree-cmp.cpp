#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000
int n, m, a, b, offset, leaf[MAX], max_tree[4 * MAX], min_tree[4 * MAX];

void init(int n) {
	for (offset = 1; offset < n; offset*=2);
	//leaf 채우기
	for (int i = 0; i < n; i++) {
		max_tree[offset + i] = leaf[i];
		min_tree[offset + i] = leaf[i];
	}

	//나머지도 채우기
	for (int i = n; i < offset; i++) {
		max_tree[i + offset] = 0;
		min_tree[i + offset] = 0;
	}

	//parent
	for (int i = offset - 1; i >= 0; i--) {
		max_tree[i] = max(max_tree[i * 2], max_tree[i * 2 + 1]);
		min_tree[i] = min(min_tree[i * 2], min_tree[i * 2 + 1]);
	}
}
int queryMax(int from, int to) {
	from += offset; to += offset;
	int res = 0;
	while (from <= to) {
		if (from % 2 == 1) res = max(res, max_tree[from++]);
		if (to % 2 == 0) res = max(res, max_tree[to--]);
		from /= 2;
		to /= 2;
	}
	return res;
}

int queryMin(int from, int to) {
	from += offset; to += offset;
	int res = 1000000001;
	while (from <= to) {
		if (from % 2 == 1) res = min(res, min_tree[from++]);
		if (to % 2 == 0) res = min(res, min_tree[to--]);
		from /= 2;
		to /= 2;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> leaf[i];
	init(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		cout << queryMin(a, b) << " " << queryMax(a, b) << '\n';
	}
	return 0;
}