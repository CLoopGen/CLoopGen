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
    int32_t *array = (int32_t*)malloc(M * sizeof(int32_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        array[i] = i * 2;
        for (j = 0; j < N; j++) {
            array[i] += j;
        }
    }
    // Introduce loop-carried WAW and RAW dependencies: each array[i] is written once per outer loop,
    // then repeatedly updated in the inner loop depending on previous values.
    // Data dependency chain within each outer iteration creates a carried dependence across inner iterations.
    free(array);
}
