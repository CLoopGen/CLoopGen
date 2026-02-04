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
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute sequential indices (could be randomized or reordered in real indirect patterns)
    for (i = 0; i < len; i++) {
        indices[i] = i;
    }

    // Traverse using indirect addressing
    for (i = 0; i < len; i++) {
        size_t idx = indices[i]; // Load index indirectly
        if (idx >= len || !s[idx]) {
            break;
        }
    }

    // Map final state: set `i` to number of valid consecutive chars scanned
    for (i = 0; i < len && s[i]; i++)
        ;

    free(indices);
}
