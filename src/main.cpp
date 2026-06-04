#include <iostream>
#include <string>
#include "Game.hpp"
#include "Trie.hpp"
#include "GamesDatabase.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 3) { 
        cout << "Usagem: ./app k (int) prefix (string)" << endl;
        return 1;
    }

    int k = stoi(argv[1]);
    string prefix = argv[2];

    Trie trie;
    for (int i = 0; i < numberOfGames; i++) {
        trie.insert(&games[i]);
    }

    std::vector<Game*> results = trie.autocomplete(prefix, k);

    
    return 0;
}