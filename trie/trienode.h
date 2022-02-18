#ifndef TRIENODE_H
#define TRIENODE_H

typedef struct trie_node{
    void * parent;
    void * children[26];
    int value;
    int word_length;
} trie_node_h;

trie_node_h * construct_node();
void add_child(trie_node_h * parent, trie_node_h * child, int index);
void increment_value();

#endif