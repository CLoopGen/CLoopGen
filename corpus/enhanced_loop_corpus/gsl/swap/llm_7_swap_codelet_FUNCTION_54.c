#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *buffer = malloc(K * sizeof(uint64_t));
    if (!buffer) return;
    for (i = 0; i < K; i++) {
        buffer[i] = i;
    }
    // Eliminate loop-carried dependencies entirely: each iteration writes to independent memory location.
    // No RAW, WAR, or WAW dependencies between iterations (assuming no aliasing).
    // Data independence enables full parallelization.
    free(buffer);
}
