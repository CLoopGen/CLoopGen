#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t n;
extern  ssize_t k;
extern double r;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access pattern using an index array to access values indirectly
    // We precompute indices in an array and traverse them indirectly, changing access locality
    ssize_t *indices = (ssize_t*)malloc((n - k) * sizeof(ssize_t));
    if (!indices) return; // Handle allocation failure

    // Pre-fill indices array with sequential values: k+1, k+2, ..., n
    for (ssize_t j = 0; j < n - k; j++) {
        indices[j] = k + 1 + j;
    }

    r = 1.0; // Reset r
    for (i = 0; i < n - k; i++) {
        r *= indices[i]; // Indirect access via lookup table
    }

    free(indices);
}
