#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Simulate an indirect access pattern using a virtual index map (i * 1)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute sequential indices (could be randomized or reordered for true indirection)
    for (size_t j = 0; j < len; j++) {
        indices[j] = j;
    }

    i = 0;
    for (size_t j = 0; j < len; j++) {
        i = indices[j];
        if (!s[i]) {
            break;
        }
    }
    // If loop ended without hitting null, set i to len
    if (i < len && s[i]) i = len;

    free(indices);
}
