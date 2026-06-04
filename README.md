# Sistema de Autocomplete de Jogos com Trie

## Alunos

- Rafael Gontijo Ferreira
- Rudá Dantas Ruoso Brandão

## Estrutura do Projeto

<pre>
├── bins
│   ├── app
│   └── check_database
├── enunciados
│   ├── COMO_TESTAR_BASE.md
│   └── lista_4.md
├── Makefile
├── README.md
├── relatorio
│   └── relatorio.tex
└── src
    ├── check_database.cpp
    ├── Game.cpp
    ├── Game.hpp
    ├── GamesDatabase.cpp
    ├── GamesDatabase.hpp
    ├── main.cpp
    ├── Trie.cpp
    └── Trie.hpp
</pre>

## Compilação

#### Pré-requisitos

- g++ 
- make

#### Compilar

```bash
make
```

#### Executar

```bash
./bins/app k "prefixo"
```

Exemplo:

```bash
./bins/app 3 ha
./bins/app 3 "half l" # Caso o prefixo possua espaços
```

#### Limpar

```bash
make clean
```