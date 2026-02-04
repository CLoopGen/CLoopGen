#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second character)
    for (p = item_str; *p && *p != '|'; p += 2) {
        if (*(p + 1) != '\0' && *(p + 1) == ' ')
            (*nb_items)++;
        if (*p == ' ')
            (*nb_items)++;
    }
}
