#include <stdlib.h>
#include "charnode.h"

char_node_t * construct_char_node(char c) {
    char_node_t * node = (char_node_t*)malloc(sizeof(char_node_t));
    node->next = NULL;
    node->prev = NULL;
    node->data = c;
    return node;
}

void delete_char_node(char_node_t * node) {
    node->next = NULL;
    node->prev = NULL;
    node->data = 0;
    free(node);
}