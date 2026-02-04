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
    volatile uint64_t temp;
    uint64_t accumulator = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            temp = (uint64_t)(i * N + j);       // Eliminate inter-iteration dependencies
            accumulator ^= temp;                // WAW on accumulator, but no loop-carried dependency
        }
    }
    // Use accumulator to prevent optimization away
    if (accumulator == 0) {
        accumulator = 1;
    }
}
