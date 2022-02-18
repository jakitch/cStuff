#include <stdio.h>
#include "linkedchar.h"

int main() {

    linked_char_t * list = construct_linked_char();
    add_char(list, 'J');
    add_char(list, 'a');
    add_char(list, 'r');
    add_char(list, 'e');
    add_char(list, 'd');
    printf("%s\n", to_str(list));
    add_char(list, 's');
    printf("%s\n", to_str(list));
    remove_last(list);
    printf("%s\n", to_str(list));
    remove_last(list);
    printf("%s\n", to_str(list));
    add_char(list, 'd');
    printf("%s\n", to_str(list));
    add_str(list, " Kitchen");
    printf("%s\n", to_str(list));
    remove_last(list);
    printf("%s\n", to_str(list));
    add_char(list, 'n');
    printf("%s\n", to_str(list));
    return 0;
}