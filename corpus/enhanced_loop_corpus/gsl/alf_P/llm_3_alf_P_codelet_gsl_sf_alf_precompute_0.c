#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern double *alm;
extern size_t l;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via an index array
    // Simulate indirect access pattern using precomputed indices (assuming index array is available)
    // For realism, we simulate a strided access pattern by stepping through k with non-unit stride in access
    size_t *indices = (size_t*)malloc(2 * (lmax - 1) * sizeof(size_t));
    if (!indices) return; // handle alloc failure
    size_t idx = 0;
    for (size_t temp_l = 2; temp_l <= lmax; ++temp_l) {
        indices[idx++] = 2 * (temp_l - 2); // simulate reordered or indirect addressing
        indices[idx++] = 2 * (temp_l - 2) + 1;
    }
    idx = 0;
    for (l = 2; l <= lmax; ++l) {
        alm[indices[idx++]] = 2. - 1. / (double)l;
        alm[indices[idx++]] = -(1. - 1. / (double)l);
        ++k;
    }
    free(indices);
}
