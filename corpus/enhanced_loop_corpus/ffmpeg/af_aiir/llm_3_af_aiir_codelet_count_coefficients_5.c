#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive pointer dereferencing with offset-based access (simulate array indexing)
    size_t i = 0;
    char current;
    for (p = item_str; (current = *(p + i)) && current != '|'; i++) {
        if (*(p + i) == ' ')
            (*nb_items)++;
    }
}
