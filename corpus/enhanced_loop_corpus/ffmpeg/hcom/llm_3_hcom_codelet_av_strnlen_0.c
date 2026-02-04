#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array (simulated stride pattern)
    // Using an auxiliary index array to simulate indirect access pattern within valid bounds
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Create indirect access pattern: reverse order traversal
    for (size_t j = 0; j < len; j++) {
        indices[j] = len - 1 - j;
    }

    i = 0;
    for (size_t idx = 0; idx < len; idx++) {
        i = indices[idx];
        if (!s[i]) break;
    }

    // If no null found, set i to len
    if (i == len - 1 && s[i]) i = len;

    free(indices);
}
