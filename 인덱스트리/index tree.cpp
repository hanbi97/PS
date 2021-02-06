#include <iostream>
using namespace std;

#define MAX 100000
typedef long long lld;

int n, q, x, y, a, b, offset;
lld cards[MAX];
lld tree[4 * MAX];

void init() {
	for (offset = 1; offset < n; offset *= 2);

	//leaf
	for (int i = 0; i < n; i++)	tree[offset + i] = cards[i];
	for (int i = n; i < offset; i++)tree[offset + i] = 0;
	//sum
	for (int i = offset - 1; i > 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

lld query(int start, int end) {
	lld res = 0;
	start += offset, end += offset;

	while (start <= end) {
		if (start % 2 == 1) {
			res += tree[start++];
		}
		if (end % 2 == 0) {
			res += tree[end--];
		}
		start /= 2; end /= 2;
	}
	return res;
}

void update(int idx, lld value) {
	idx += offset;
	tree[idx] = value;
	idx /= 2;
	while (idx > 0) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> cards[i];
	init();
	while (q--) {
		cin >> x >> y >> a >> b;
		if (x > y) {
			cout << query(y - 1, x - 1) << '\n';
		}
		else {
			cout << query(x - 1, y - 1) << '\n';
		}
		update(a - 1, b);
	}
	return 0;
}