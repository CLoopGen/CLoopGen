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
    uint64_t* array = (uint64_t*)malloc(M * sizeof(uint64_t));
    if (!array) exit(1);
    for (i = 0; i < M; i++) {
        array[i] = i * i;
        for (j = 0; j < N; j++) {
            array[i] += j;
        }
    }
    // Introduce loop-carried dependence via array[i]: each outer loop index writes and accumulates within inner loop.
    // RAW: j is read in inner loop, i is read in outer.
    // WAW: each outer iteration writes to distinct array[i], so no cross-iteration WAW.
    // WAR: none due to ordered execution.
    free(array);
}
