#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    size_t len = 0;
    char *temp = item_str;
    while (temp[len]) len++; // Compute length without do/while

    for (size_t i = 0; i < len; i++) {
        char c = *(item_str + i); // Indirect access via computed offset
        if (c == ' ' || c == '|')
            (*nb_items)++;
    }
}
