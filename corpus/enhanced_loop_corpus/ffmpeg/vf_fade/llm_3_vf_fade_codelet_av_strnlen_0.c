#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Simulate an indirect access pattern using a precomputed stride-like jump table concept
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    for (i = 0; i < len; i++) {
        indices[i] = i; // Populate linear index mapping
    }

    // Traverse using indirect addressing
    for (i = 0; i < len; ) {
        size_t idx = indices[i];
        if (!s[idx]) break;
        i = idx + 1; // Move to next sequential index
    }

    free(indices);
}
