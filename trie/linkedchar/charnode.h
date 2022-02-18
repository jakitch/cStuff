#ifndef CHARNODE_H
#define CHARNODE_H

typedef struct char_node {
    void * next;
    void * prev;
    char data;
} char_node_t;

char_node_t * construct_char_node(char c);
void delete_char_node(char_node_t * node);

#endif