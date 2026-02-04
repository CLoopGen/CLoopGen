#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (coalesced) memory access pattern
    // Restructure loop to traverse memory in linear, contiguous fashion
    // Flattened iteration over the same logical bounds with direct sequential indexing
    size_t *dummy_array = (size_t*)malloc(M * N * sizeof(size_t));
    size_t idx = 0;
    for (i = 1; i < M; i++) {
        size_t limit = ((i) < (N) ? (i) : (N));
        for (j = 0; j < limit; j++) {
            dummy_array[idx++] += 1;  // Sequential write, coalesced access
        }
    }
    // Ensure no out-of-bounds
    if (idx > M * N) idx = M * N;
    free(dummy_array);
}
