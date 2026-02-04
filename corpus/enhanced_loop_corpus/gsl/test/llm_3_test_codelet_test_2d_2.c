#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t tda;
extern size_t i;
extern double *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect access via precomputed indices (e.g., scattering pattern)
    size_t *indices = (size_t*)malloc(N * tda * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (i = 0; i < N * tda; i++) {
        indices[i] = i; // Identity mapping for realism, but enables indirect access
    }
    for (i = 0; i < N * tda; i++) {
        size_t idx = indices[i];
        data[idx] = 12345. + idx;
    }
    free(indices);
}
