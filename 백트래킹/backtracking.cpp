#include <iostream>
using namespace std;

int l, c;
bool visited[26], vowels[26], consonants[26];
char input;
//모음은 최소한개 자음은 최소 두개

void dfs(int vowel, int consonant, int cnt, int idx) {
	if (cnt == l) {
		if (vowel >= 1 && consonant >= 2) {
			for (int i = 0; i < 26; i++) {
				if (visited[i]) {
					cout << char(i + 'a');
				}
			}
			cout << '\n';
		}
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (!visited[i]) {
			if (vowels[i]) {//모음고르기
				visited[i] = true;
				dfs(vowel + 1, consonant, cnt + 1,i+1);
				visited[i] = false;
			}
			if (consonants[i]) {//자음고르기
				visited[i] = true;
				dfs(vowel, consonant+1, cnt + 1,i+1);
				visited[i] = false;
			}
		}
	}
}
int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> input;
		if (input == 'a' || input == 'e' || input == 'o' || input == 'i' || input == 'u') {
			vowels[input - 'a'] = true;
		}
		else { 
			consonants[input - 'a'] = true;
		}
	}
	dfs(0, 0, 0,0);
}