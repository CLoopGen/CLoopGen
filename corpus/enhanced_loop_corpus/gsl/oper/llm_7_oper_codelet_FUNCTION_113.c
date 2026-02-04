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
    if (!accum) exit(1);
    for (i = 0; i < M; i++) {
        accum[i] = (i > 0) ? accum[i-1] + i : i; // Introduce loop-carried RAW dependency on accum[i-1]
        for (j = 0; j < N; j++) {
            accum[i] += j;
        }
    }
    // Creates loop-carried dependence in outer loop: each iteration depends on previous via accum[i-1]
    // Inner loop contributes to same element, forming WAW and WAR within outer loop context
    free(accum);
}
