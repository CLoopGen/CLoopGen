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
        for (j = i + 1; j < N; j++) {
            sums[i] += j; // WAW dependency eliminated by isolating per-outer-loop accumulation
        }
    }
    free(sums);
}
