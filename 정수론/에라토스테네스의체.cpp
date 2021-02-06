#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1001

int n, k, cnt, ans;
bool chk[MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	memset(chk, true, sizeof(chk));
	bool flag = true;
	while (flag) {
		int p = 0;
		for (int i = 2; i <= n; i++) {
			if (chk[i]) {
				p = i;
				break;
			}
		}

		for (int i = 1; p * i <= n; i++) {
			if (chk[p * i]) {
				chk[p * i] = false;
				cnt++;
			}
			if (cnt == k) {
				ans = p * i;
				flag = false;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}