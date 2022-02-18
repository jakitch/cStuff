#include <stdlib.h>
#include "trienode.h"

trie_node_h * construct_node(){

    trie_node_h * node = (trie_node_h*)malloc(sizeof(trie_node_h));
    //point children to blank trie_node_h array in memory
    *(node->children) = (trie_node_h*)malloc(sizeof(node) * 26);
    node->value = 0;
    node->word_length = 0;
    node->parent = NULL;
    for(int i = 0; i < 26; i++){
        node->children[i] = NULL;
    }
    return node;
}
void add_child(trie_node_h * parent, trie_node_h * child, int index){

    child->parent = parent;
    (parent->children)[index] = child;
}
void increment_value(trie_node_h * node){

    (node->value)++;
}