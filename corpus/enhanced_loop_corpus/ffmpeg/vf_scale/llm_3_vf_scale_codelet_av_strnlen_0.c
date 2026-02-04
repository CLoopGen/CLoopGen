#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate index array
    // Simulate indirect access using an index map (for illustration, use simple sequential indices but accessed indirectly)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Initialize indirect indices (could be rearranged for different patterns, here kept sequential for correctness)
    for (size_t j = 0; j < len; j++) {
        indices[j] = j;
    }

    i = 0;
    for (; i < len; i++) {
        size_t idx = indices[i]; // Indirect access through index array
        if (idx >= len || s[idx] == '\0') {
            break;
        }
    }

    free(indices);
}
