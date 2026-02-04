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
    uint64_t* accum = (uint64_t*)calloc(M, sizeof(uint64_t));
    if (!accum) return;
    for (i = 0; i < M; i++) {
        accum[i] = 0;
        for (j = 0; j < N; j++) {
            accum[i] += i + j; // Loop-carried dependence: each iteration updates accum[i]
        }
    }
    // Introduces loop-carried RAW dependency within outer loop via accum[i]
    // Eliminates cross-iteration dependencies in inner loop by isolating per-i accumulation
    free(accum);
}
