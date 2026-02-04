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
    int stride = 1;
    char *ptr = item_str;
    for (; ptr[0] != '\0'; ptr += stride) {
        if (ptr[0] == delimiter)
            (*nb_items)++;
    }
}
