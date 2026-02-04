#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated with offset indexing)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute sequential indices (could be randomized or reordered in real indirect pattern)
    for (i = 0; i < len; i++)
        indices[i] = i;

    // Traverse using indirect access
    for (i = 0; i < len; i++) {
        size_t idx = indices[i]; // Simulate indirect lookup
        if (idx >= len || !s[idx]) {
            // Update original `i` to reflect current logical position in string
            i = idx;
            break;
        }
    }

    free(indices);
}
