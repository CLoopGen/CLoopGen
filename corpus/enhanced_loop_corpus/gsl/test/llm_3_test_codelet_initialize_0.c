#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    size_t *indices = malloc(N * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (size_t i = 0; i < N; i++) {
        indices[i] = i; // Populate index mapping
    }
    for (size_t i = 0; i < N; i++) {
        data[indices[i]] = indices[i];
    }
    free(indices);
}
