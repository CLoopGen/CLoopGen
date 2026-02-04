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
    // Precompute indirect indices (reverse order access)
    size_t len = ((M) < (N) ? (M) : (N));
    for (size_t idx = 0; idx < len; idx++) {
        indices[idx] = len - 1 - idx;
    }
    for (i = 0; i < len; i++) {
        // Indirect memory access via index array: reverse traversal pattern
        // Simulates irregular or data-dependent access patterns
        volatile size_t pos = indices[i]; // prevent optimization
    }
    free(indices);
}
