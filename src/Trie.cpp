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

bool Trie::contains(std::string title) {
    std::string key = toSearchKey(title);
    TrieNode* current = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';

        if (current->children[index] == nullptr) {
            return false;
        }

        current = current->children[index];
    }

    return current->isEndOfTitle;
}


void Trie::collectGamesSubtree(TrieNode* node, std::vector<Game*>& games) {
    if (node->isEndOfTitle) {
        games.push_back(node->game);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != nullptr) {
            collectGamesSubtree(node->children[i], games);
        }
    }
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k) {

    std::vector<Game*> results;

    if (k <= 0) return results;

    std::string key = toSearchKey(prefix);
    TrieNode* current = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';

        if (current->children[index] == nullptr) {
            return results;
        }

        current = current->children[index];
    }

    collectGamesSubtree(current, results);
    sortResults(results);

    if (results.size() > k) {
        results.resize(k);
    }

    return results;
}
std::string Trie::toSearchKey(std::string text) {
    std::string key = "";
    for (int i = 0; i < text.length(); i++) {
        
        if (isspace(text[i])) continue;
        key += tolower(text[i]);
    
    }
    return key;
}

// insertion sort
// TODO: Rever sorts implementados
void Trie::sortResults(std::vector<Game*>& games) {
    for (int i = 1; i < games.size(); i++) {
        Game* key = games[i];
        int j = i - 1;

        while (j >= 0) {
            bool swap;
            if (games[j]->popularity != key->popularity)
                swap = games[j]->popularity < key->popularity;
            else
                swap = games[j]->title > key->title;

            if (!swap) break;

            games[j + 1] = games[j];
            j--;
        }

        games[j + 1] = key;
    }
}

