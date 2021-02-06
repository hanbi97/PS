#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

#define MAX 1001
int dp[MAX][MAX];
string str1, str2, ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> str1 >> str2;
	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (str1[i] == str2[j]) { //같은경우
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	
	//식 거꾸로 돌려서 찾음
	int a = str1.size(); int b = str2.size();
	stack<char> st;
	while (dp[a][b] != 0) {
		if (dp[a][b] == dp[a - 1][b]) {
			a--;
		}
		else if (dp[a][b] == dp[a][b - 1]) {
			b--;
		}
		else {
			st.push(str1[a-1]);
			a--; b--;
		}
	}
	
	cout << dp[str1.size()][str2.size()] << '\n';
	while (!st.empty()) {
		cout << st.top(); st.pop();
	}

	return 0;
}