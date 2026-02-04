#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via index array (simulated with pointer arithmetic)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute sequential indices (could be randomized or reordered in real indirect pattern)
    for (i = 0; i < len; i++) {
        indices[i] = i;
    }

    // Traverse using indirect addressing
    for (i = 0; i < len; i++) {
        size_t idx = indices[i]; // Indirect access
        if (idx >= len || !s[idx]) {
            // Adjust original `i` to reflect termination condition of original loop
            i = idx; // Approximate final value of `i`
            break;
        }
    }

    free(indices);
}
