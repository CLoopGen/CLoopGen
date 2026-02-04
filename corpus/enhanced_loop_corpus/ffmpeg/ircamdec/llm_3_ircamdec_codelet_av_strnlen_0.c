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
    if (!access_order) return;

    // Build indirect access pattern: reverse order traversal
    for (size_t j = 0; j < len; j++) {
        access_order[j] = &s[len - 1 - j];
    }

    i = 0;
    for (size_t idx = 0; idx < len; idx++) {
        if (*access_order[idx] == '\0') break;
        i = len - 1 - idx; // map back to forward index
    }

    // Cleanup
    free(access_order);
}
