#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t* array = (uint64_t*) malloc(K * sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < K; i++) {
        array[i] = i;
        if (i > 0) {
            array[i] += array[i-1]; // Introduce loop-carried RAW (read-after-write) dependency
        }
    }
    free(array);
}
