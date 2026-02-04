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
    int64_t *sums = (int64_t*)calloc(M, sizeof(int64_t));
    if (!sums) return;
    for (i = 1; i < M; i++) {
        sums[i] = sums[i-1]; // Introduce loop-carried RAW dependency
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
            sums[i] += i * j; // Accumulate with loop-independent computation
        }
    }
    free(sums);
}
