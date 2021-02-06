class Trie {
public:
	Trie* child[26];
	bool finish;
	Trie() {
		for (int i = 0; i < 26; i++) this->child[i] = NULL;
		this->finish = false;
	}

	int chToint(char ch) {
		return ch - 'A';
	}

	void insert(string word, int idx) {
		if (word[idx] == NULL) {
			finish = true;
			return;
		}
		else {
			int curr = chToint(word[idx]);
			if (child[curr] == NULL) child[curr] = new Trie();
			child[curr]->insert(word, idx + 1);
		}
	}

	bool find(string word, int idx) {
		if (word[idx] == NULL) {
			if (finish) {
				return true;
			}
			return false;
		}
		else {
			int curr = chToint(word[idx]);
			if (child[curr] == NULL)return false;
			return child[curr]->find(word, idx + 1);
		}
	}
};
