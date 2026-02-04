#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index array (simulated with pointer arithmetic)
    // Simulate indirect indexing by treating each character address as part of an index list
    size_t len = 0;
    char* temp = item_str;
    while (temp[len]) len++; // Compute length for bounds

    for (size_t i = 0; i < len; i++) {
        char* indirect_p = item_str + i; // Indirect access through computed offset
        if (*indirect_p == '|') {
            (*nb_items)++;
        }
    }
}
