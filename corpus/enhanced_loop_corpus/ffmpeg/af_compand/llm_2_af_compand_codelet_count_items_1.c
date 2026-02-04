#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every 2nd character)
    for (p = item_str; *p; p += 2) {
        if (*p == ' ' || *p == '|')
            (*nb_items)++;
        // Handle potential overflow for odd-length strings
        if (*(p+1) && (*(p+1) == ' ' || *(p+1) == '|'))
            (*nb_items)++;
    }
}
