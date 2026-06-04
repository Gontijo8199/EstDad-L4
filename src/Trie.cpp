#include "Trie.hpp"
#include <cctype>

TrieNode::TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        this->children[i] = nullptr;
    }
    this->isEndOfTitle = false;
    this->game = nullptr;
}

TrieNode::~TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (this->children[i] != nullptr) {
            delete this->children[i];
            this->children[i] = nullptr;
        }
    }
}

Trie::Trie() {
    this->root = new TrieNode();
}

Trie::~Trie() {
    delete root;
}

bool Trie::insert(Game* game) {
    std::string key = toSearchKey(game->title);
    TrieNode* current = root;

    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a'; // conversão de índice 

        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
        }

        current = current->children[index];
    }

    current->isEndOfTitle = true;
    current->game = game;
    return true;
}

bool Trie::contains(std::string title){}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k){}

std::string Trie::toSearchKey(std::string text) {
    std::string key = "";
    for (int i = 0; i < text.length(); i++) {
        
        if (isspace(text[i])) continue;
        key += tolower(text[i]);
    
    }
    return key;
}

void Trie::sortResults(std::vector<Game*>& games){}