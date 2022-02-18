#ifndef TRIE_H
#define TRIE_H
#include "trienode.h"

typedef struct trie{
    int node_count;
    int word_count;
    trie_node_h * root;
} trie_h;

trie_h * construct_trie();
void add(trie_h * tree, char word[]);
trie_node_h * find(trie_h * tree, char word[]);
void print_trie(trie_h * tree);
int equals(trie_h * tree1, trie_h * tree2);
int hash_code(trie_h * tree);

#endif