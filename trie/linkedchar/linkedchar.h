#ifndef LINKEDCHAR_H
#define LINKEDCHAR_H

#include "charnode.h"

typedef struct linked_char {
    char_node_t * first;
    char_node_t * last;
    char * str;
    int num_nodes;
} linked_char_t;

linked_char_t * construct_linked_char();
void delete_linked_char(linked_char_t * list);
void add_char(linked_char_t * list, char c);
void add_str(linked_char_t * list, char str[]);
void remove_last(linked_char_t * list);
char * to_str(linked_char_t * list);

#endif