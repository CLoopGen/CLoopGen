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
    uint64_t *array = (uint64_t*)calloc(M, sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            array[i] = i + j; // Write to array[i] in inner loop – introduces WAR/WAW if parallelized
        }
        // RAW dependency: each array[i] depends on all inner-loop writes before next i iteration
    }
    free(array);
    // Introduces memory-based data dependencies and loop-carried dependence through array updates
}
