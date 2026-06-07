#ifndef TRIE_HPP
#define TRIE_HPP

#include "Game.hpp"
#include <vector>

#define ALPHABET_SIZE 36 // a-z (0-25) + 0-9 (26-35)

class TrieNode {

public:

    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfTitle;
    Game* game;

    TrieNode();
    ~TrieNode();
};

class Trie {

private:

    TrieNode* root;

public:

    Trie();
    ~Trie();

    bool insert(Game* game);
    bool contains(std::string title);

    std::vector<Game*> autocomplete(std::string prefix, int k);

    std::string toSearchKey(std::string text);
    void sortResults(std::vector<Game*>& games);
    std::vector<Game*> selectK(std::vector<Game*>& games, int k);

    // Outros métodos auxiliares, se necessário

    // percorre toda a subárvore coletando jogos onde isEndOfTitle == true
    // facilita o autocomplete
    void collectGamesSubtree(TrieNode* node, std::vector<Game*>& games);

    // fix: bugs de conversão
    int charToIndex(char c);

};

#endif