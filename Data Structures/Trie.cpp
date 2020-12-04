#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26; 

struct TrieNode {
	struct TrieNode *children[]
	bool isEndOfWord;
};

struct TrieNode *getNode() {
	struct TrieNode *pNode = new TrieNode;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		pNode -> children[i] = NULL; 
	}
	pNode -> isEndOfWord = false;
	return pNode;
}

void insert(struct TrieNode *root, string key) {
	struct TrieNode *pCrawl = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!pCrawl -> children[index]) {
			pCrawl -> children[index] = getNode();
		}
		pCrawl = pCrawl -> children[index];

		pCrawl -> isEndOfWord = true;
	}
}

bool search(struct TrieNode *root, string key) {
	struct TrieNode *pCrawl = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!pCrawl -> children[index]) 
			return false;
		pCrawl = pCrawl -> children[index];
	}
	return (pCrawl != NULL && pCrawl -> isEndOfWord)
}

int main() {
	
}