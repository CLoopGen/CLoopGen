#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(((M) < (N) ? (M) : (N)) * sizeof(size_t));
    if (!indices) return;
    // Precompute indirect access indices (reverse order)
    size_t len = ((M) < (N) ? (M) : (N));
    for (size_t k = 0; k < len; k++) {
        indices[k] = len - 1 - k; // reverse indexing
    }
    // Indirect memory access using computed indices
    for (i = 0; i < len; i++) {
        volatile size_t dummy = indices[i]; // simulate data access via indirection
    }
    free(indices);
}
