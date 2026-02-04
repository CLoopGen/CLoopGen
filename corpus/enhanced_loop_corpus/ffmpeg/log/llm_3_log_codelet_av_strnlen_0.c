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
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute sequential indices (could be randomized or reordered in real indirect patterns)
    for (i = 0; i < len; i++)
        indices[i] = i;

    // Traverse using indirect addressing
    for (i = 0; i < len; i++) {
        size_t idx = indices[i];
        if (!s[idx]) break;
    }
    // Finalize i as the offset in original sequence
    free(indices);
}
