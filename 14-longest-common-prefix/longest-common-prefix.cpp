#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    int childCount;

    TrieNode() {
        isEnd = false;
        childCount = 0;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for(char c : word) {
            int index = c - 'a';

            if(node->children[index] == NULL) {
                node->children[index] = new TrieNode();
                node->childCount++;
            }

            node = node->children[index];
        }

        node->isEnd = true;
    }

    string longestCommonPrefix(string firstWord) {
        string prefix = "";
        TrieNode* node = root;

        for(char c : firstWord) {
            int index = c - 'a';

            if(node->childCount == 1 && !node->isEnd) {
                prefix += c;
                node = node->children[index];
            }
            else {
                break;
            }
        }

        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 0) return "";

        Trie trie;

        for(string s : strs)
            trie.insert(s);

        return trie.longestCommonPrefix(strs[0]);
    }
};