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
    uint64_t* array = (uint64_t*)calloc(M, sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            array[i] = i + j; // Write to array[i] in inner loop — introduces loop-carried dependence on array[i]
        }
    }
    // Introduces WAW on array[i] across inner loop iterations, but no cross-iteration dependence in outer loop.
    // Each outer iteration i writes to distinct array element — no inter-outer-loop dependency.
    // Eliminated any false sharing potential by using non-overlapping indices.
    free(array);
}
