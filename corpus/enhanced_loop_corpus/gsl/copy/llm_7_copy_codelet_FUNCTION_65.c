#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *array = (uint64_t*)malloc(sizeof(uint64_t) * ((M) < (N) ? (M) : (N)));
    if (!array) exit(1);
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        array[i] = i > 0 ? array[i-1] + i : 0;
    }
    // Introduce a read-after-write (RAW) loop-carried dependency: each iteration depends on the previous.
    // This creates a sequential data dependency chain, preventing parallelization.
    free(array);
}
