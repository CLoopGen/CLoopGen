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
    uint64_t *sums = (uint64_t*)calloc(M, sizeof(uint64_t));
    if (!sums) return;
    for (i = 0; i < M; i++) {
        sums[i] = 0;
        for (j = 0; j < N; j++) {
            sums[i] += i + j;
        }
    }
    // Introduce loop-carried dependence through memory: each outer loop index writes to a unique
    // location in `sums`, eliminating cross-iteration dependencies in the outer loop.
    // Inner loop has a reduction-style RAW dependency carried by `sums[i]`.
    // WAR and WAW hazards avoided via per-iteration memory location.
    free(sums);
}
