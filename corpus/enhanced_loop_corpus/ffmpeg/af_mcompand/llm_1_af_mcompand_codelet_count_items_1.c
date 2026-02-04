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
    for (p = item_str; *p && *(p + 1); p += 2) {  // Process two characters per iteration, adjusting loop stride
        if (*p == delimiter)
            (*nb_items)++;
        if (*(p + 1) == delimiter)
            (*nb_items)++;
    }
    // Handle the last character if the string length is odd
    if (*p && *p == delimiter)
        (*nb_items)++;
}
