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
    uint64_t* accum = (uint64_t*)malloc(M * sizeof(uint64_t));
    for (i = 0; i < M; i++) {
        accum[i] = 0;
        for (j = 0; j < N; j++) {
            accum[i] += i + j;
        }
    }
    // Eliminate all loop-carried dependencies: each outer iteration writes to distinct accum[i].
    // Only intra-outer-loop dependencies (RAW in inner loop), no cross-iteration dependencies across outer loop.
    // WAR/WAW avoided by per-outer-loop-element accumulation.
    free(accum);
}
