#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

trie_h * construct_trie(){

    trie_h * tree = (trie_h*)malloc(sizeof(trie_h));
    tree->node_count = 1;
    tree->word_count = 0;
    tree->root = construct_node();
    return tree;
}

void add(trie * tree, char word[]){

    trie_node_h * curr_node = tree->root;
    int word_length = 0;

    for(int i = 0; i < strlen(word); i++) {
        word_length++;
        int index = word[i] - 'a';
        if((curr_node->children)[index] == NULL) {
            trie_node_h * next_node = construct_node();
            add_child(curr_node, next_node, index);
            curr_node = next_node;
            (tree->node_count)++;
        }
        else
            curr_node = (curr_node->children)[index];
    }

    if(curr_node->value == 0){
        (tree->word_count)++;
        curr_node->word_length = word_length;
    }

    increment_value(curr_node);
}

trie_node_h * find(trie_h * tree, char word[]);

void print_trie_helper(trie_node_h * node) {

    if(node->value > 0)
        printf("\n");
    
    for(int i = 0; i < 26; i++){

        trie_node_h * child = (node->children)[i];

        if(child != NULL) {

            char child_letter = (char)('a' + i);
            printf("%c", child_letter);
            print_trie_helper(child);
        }
    }
}

void print_trie(trie_h * tree) {

    print_trie_helper(tree->root);
}

int equals(trie_h * tree1, trie_h * tree2);
int hash_code(trie_h * tree);

int main() {
    trie_h * test = construct_trie(); 

    add(test, "whataburger");
    add(test, "thiswontwork");
    add(test, "whatanugget");
    print_trie(test);
    return 0;
}