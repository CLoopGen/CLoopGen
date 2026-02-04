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
        data[i] = i * 2;
    }
    // Eliminate loop-carried dependencies: each iteration writes to independent memory location.
    // No RAW, WAR, or WAW dependencies between iterations — fully parallelizable.
    // Memory access is independent, enabling potential vectorization.
    free(data);
}
