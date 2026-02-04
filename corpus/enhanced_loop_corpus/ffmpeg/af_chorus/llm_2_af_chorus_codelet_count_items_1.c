#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (p = item_str; *p; p += 2) {
        if (*p == '|') {
            (*nb_items)++;
        }
        // Check next element if current stride allows and not at string end
        if (*(p + 1) && *(p + 1) == '|') {
            (*nb_items)++;
        }
    }
}
