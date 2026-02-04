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
    uint64_t *buffer = (uint64_t*)calloc(N, sizeof(uint64_t));
    if (!buffer) return;
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j++) {
            buffer[j] = buffer[i] + j; // RAW dependency on buffer[i], loop-carried via 'i'
        }
    }
    free(buffer);
    // Introduces loop-carried RAW dependency through memory accesses to 'buffer'
}
