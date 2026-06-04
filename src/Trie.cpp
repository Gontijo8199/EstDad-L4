#include<Trie.hpp>


TrieNode::TrieNode(){}
TrieNode::~TrieNode(){}

Trie::Trie(){}
Trie::~Trie(){}

bool Trie::insert(Game* game){}
bool Trie::contains(std::string title){}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k){}

std::string Trie::toSearchKey(std::string text){}
void Trie::sortResults(std::vector<Game*>& games){}