#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *data = (uint64_t*)malloc(K * sizeof(uint64_t));
    if (!data) return;
    for (i = 0; i < K; i++) {
        data[i] = i > 0 ? data[i-1] + i : i; // Introduce loop-carried RAW (read-after-write) dependency
    }
    // Ensure no immediate reuse, but dependency chain exists across iterations
    free(data);
}
