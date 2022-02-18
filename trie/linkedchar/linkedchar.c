#include <stdlib.h>
#include "linkedchar.h"

linked_char_t * construct_linked_char(){
    linked_char_t * list = (linked_char_t*)malloc(sizeof(linked_char_t));
    list->first = NULL;
    list->last = NULL;
    list->str = NULL;
    list->num_nodes = 0;

    return list;
}

void delete_linked_char(linked_char_t * list) {

    //Put every node pointer in list into an array for deletion.
    int stack_size = list->num_nodes;
    char_node_t * node_stack[stack_size];

    char_node_t * curr_node = list->first;

    for(int i = 0; i < stack_size; i++) {
        node_stack[i] = curr_node;
        curr_node = curr_node->next;
    }
    
    //Delete every node
    for(int i = 0; i < stack_size; i++) {
        delete_char_node(node_stack[i]);
    }

    list->first = NULL;
    list->last = NULL;
    if (list->str != NULL) {
        free(list->str);
        list->str = NULL;
    }
    list->num_nodes = 0;
    free(list);
}
//Add a char node to the list
void add_char(linked_char_t * list, char c) {

    //New node to add to the list.
    char_node_t * node = construct_char_node(c);

    if(list->first == NULL && list->last == NULL) {
        //Set first to the new node.
        list->first = node;
    }
    else {
        /* Point last's next node to the new node.
         * Point new node's prev node to last node in list.
         */
        list->last->next = node;
        node->prev = list->last;
    }

    list->last = node;
    list->num_nodes++;

}

void add_str(linked_char_t * list, char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        add_char(list, str[i]);
    }
}


void remove_last(linked_char_t * list) {
    
    if(list->num_nodes > 0) {
        
        char_node_t * del_node = list->last;
        
        if(list->num_nodes == 1) {
            delete_char_node(del_node);
            list->first = NULL;
            list->last = NULL;
        }
        else {
            list->last = del_node->prev;
            delete_char_node(del_node);
        }
        list->num_nodes--;
    }
}

char * to_str(linked_char_t * list) {

    if (list->str != NULL) {
        free(list->str);
        list->str = NULL;
    }

    list->str = (char *)malloc(sizeof(char)*(list->num_nodes + 1));
    char_node_t * curr_node = list->first;

    for(int i = 0; i < list->num_nodes; i++) {
        (list->str)[i] = (char)(curr_node->data);
        curr_node = curr_node->next; 
    }
    (list->str)[list->num_nodes] = '\0';

    return list->str;
}