#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate pointer array
    char **access_order = (char**)malloc(len * sizeof(char*));
    if (!access_order) return; // Handle allocation failure

    // Set up indirect access: point to each valid character address
    for (size_t j = 0; j < len; j++) {
        access_order[j] = &s[j];
    }

    // Traverse using indirect access
    for (i = 0; i < len; i++) {
        if (!(*access_order[i])) break;
    }

    free(access_order);
}
