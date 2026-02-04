#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char delimiter;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t index;
    char *start = item_str;
    for (index = 0; start[index] != '\0'; index++) {
        if (start[index] == delimiter)
            (*nb_items)++;
    }
}
