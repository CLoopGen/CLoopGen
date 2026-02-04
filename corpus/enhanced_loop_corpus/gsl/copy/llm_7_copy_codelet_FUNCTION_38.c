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
    int64_t* accum = (int64_t*)calloc(M, sizeof(int64_t));
    if (!accum) return;
    for (i = 1; i < M; i++) {
        accum[i] = accum[i-1]; // Introduce loop-carried RAW dependency: depends on previous iteration
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
            accum[i] += j; // Accumulate j into accum[i], no loop-carried dep inside inner loop
        }
    }
    free(accum);
}
