#include <iostream> 
#include <string>
#include <vector>

using namespace std;

class TrieNode {
public:
	TrieNode(char val) {
		data = val;
		children = vector<TrieNode*>(26);
		end = false;
	}
	
	vector<TrieNode*> children;
	char data;
	bool end;
};

class Trie {
public:
	Trie() {
		root = new TrieNode('/');
	}
	void insert(string word) {
		TrieNode* cur = root;
		int i = 0;
		while (cur->children[word[i] - 'a'] != NULL && i < word.size()) {
			cur = cur->children[word[i] - 'a'];
			i += 1;
		}
		while (i < word.size()) {
			TrieNode* node = new TrieNode(word[i]);
			cur->children[word[i] - 'a'] = node;
			cur = node;
			i += 1;
		}	
		cur->end = true;
	}
	
	bool search(string word) {
		TrieNode* cur = root;
		int i;
		for(i = 0; i < word.size(); i ++) {
			if(cur->children[word[i] - 'a'] == NULL) {
				return false;
			}
			else {
				cur = cur->children[word[i] - 'a'];
			}
		}

		return cur->end;
    }
	
	bool startsWith(string prefix) {
		TrieNode* cur = root;
		for(int i = 0; i < prefix.size(); i ++) {
			if(cur->children[prefix[i] - 'a'] == NULL) {
				return false;
			}
			else {
				cur = cur->children[prefix[i] - 'a'];
			}
		}
		return true;
    }
	
	TrieNode* root;
};

int main() 
{
	Trie* trie = new Trie();
	trie->insert("apple");
	cout<<trie->search("apple");
	cout<<trie->search("app");
	cout<<trie->startsWith("app");
	trie->insert("app");
	cout<<trie->search("app");
	// cout<<trie->search("apple")<<trie->search("app")<<trie->startsWith("apple");
}
