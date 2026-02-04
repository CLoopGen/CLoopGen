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
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute sequential indices (could be randomized or reordered for more complex indirect patterns)
    for (size_t j = 0; j < len; j++)
        indices[j] = j;

    for (i = 0; i < len; i++) {
        size_t idx = indices[i]; // Indirect access
        if (idx >= len || !s[idx]) {
            // Adjust final value of `i` to reflect position in original string
            i = idx;
            break;
        }
    }

    free(indices);
}
