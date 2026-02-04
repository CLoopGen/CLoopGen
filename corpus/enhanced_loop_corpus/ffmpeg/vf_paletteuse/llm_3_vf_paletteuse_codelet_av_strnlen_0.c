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

    // Set up pointers to characters in order
    for (size_t j = 0; j < len; j++) {
        access_order[j] = &s[j];
    }

    i = 0;
    for (; i < len; i++) {
        if (*access_order[i] == '\0') {
            break;
        }
    }

    free(access_order);
}
