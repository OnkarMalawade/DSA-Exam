#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure of a Trie node
struct TrieNode {
    TrieNode* Trie[256];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 256; i++) {
            Trie[i] = NULL;
        }
        isEnd = false;
    }
};

void InsertTrie(TrieNode* root, const string& s) {
    TrieNode* temp = root;
    for (size_t i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (temp->Trie[ch] == NULL) {
            temp->Trie[ch] = new TrieNode();
        }
        temp = temp->Trie[ch];
    }
    temp->isEnd = true;
}

void printSuggestions(TrieNode* root, const string& res) {
    if (root->isEnd) {
        cout << res << " ";
    }
    for (int i = 0; i < 256; i++) {
        if (root->Trie[i] != NULL) {
            char ch = static_cast<char>(i);
            printSuggestions(root->Trie[i], res + ch);
        }
    }
}

bool checkPresent(TrieNode* root, const string& key) {
    for (size_t i = 0; i < key.length(); i++) {
        char ch = key[i];
        if (root->Trie[ch] == NULL) {
            printSuggestions(root, key.substr(0, i));
            return false;
        }
        root = root->Trie[ch];
    }
    if (root->isEnd) {
        return true;
    }
    printSuggestions(root, key);
    return false;
}

int main() {
    vector<string> str;
    str.push_back("gee");
    str.push_back("geeks");
    str.push_back("ape");
    str.push_back("apple");
    str.push_back("geeksforgeeks");
    str.push_back("ra");
    str.push_back("rats");
    str.push_back("ca");
    str.push_back("cat");
    str.push_back("man");
    str.push_back("mango");
    str.push_back("bat");
    str.push_back("batman");
    str.push_back("spi");
    str.push_back("spider");
    str.push_back("gent");
    str.push_back("gentleman");

    // Initialize a Trie
    TrieNode* root = new TrieNode();

    // Insert strings to trie
    for (size_t i = 0; i < str.size(); i++) {
        InsertTrie(root, str[i]);
    }
	
    // Get user input
    cout << "Enter a key: ";
    string key;
    cin >> key;

    // Check if key is present in Trie
    if (checkPresent(root, key)) {
        cout << "YES";
    }

    // Clean up memory
    delete root;

    return 0;
}

