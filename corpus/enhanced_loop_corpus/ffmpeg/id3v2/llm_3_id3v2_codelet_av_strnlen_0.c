#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Simulate indirect access by creating a virtual stride through indices
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Initialize index mapping: identity mapping for realism
    for (size_t j = 0; j < len; j++) {
        indices[j] = j;
    }

    i = 0;
    for (size_t idx = 0; idx < len; idx++) {
        i = indices[idx];
        if (!s[i]) break;
    }

    free(indices);
}
