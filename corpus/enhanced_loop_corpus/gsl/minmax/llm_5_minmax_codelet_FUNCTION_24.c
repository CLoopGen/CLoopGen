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
            array[i] += i * j; // Introduce loop-carried WAW dependency on array[i] across inner loop
        }
    }

    // Ensure side effect to prevent optimization
    if (array[0] < 0) {
        free(array);
        return;
    }
    free(array);
}
