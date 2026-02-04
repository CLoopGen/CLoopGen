#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a local array
    uint64_t *data = (uint64_t*)aligned_alloc(64, K * sizeof(uint64_t));
    for (i = 0; i < K; i++) {
        data[i] = i * 2;
    }
    free(data);
}
