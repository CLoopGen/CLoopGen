#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern size_t *current_depth;
extern size_t depth;
extern size_t number_threads;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array
    // Simulate indirect access via a precomputed permutation (conceptual; assume small thread count)
    size_t indices[8];
    size_t n = (number_threads > 8) ? 8 : number_threads; // Limit for fixed-size helper array
    for (size_t j = 0; j < n; j++)
        indices[j] = ((j * 7 + 3) % n); // Generate pseudo-random permutation

    for (i = 0; i < (ssize_t)n; i++) {
        size_t idx = indices[i];
        if (idx != 0 && depth < current_depth[idx]) // skip idx 0 as original starts at 1
            depth = current_depth[idx];
    }
    // Handle remaining elements directly if number_threads > n
    for (i = n; i < (ssize_t)number_threads; i++)
        if (depth < current_depth[i])
            depth = current_depth[i];
}
