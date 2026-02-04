#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t* array = (uint64_t*) malloc(loop_lim * sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < loop_lim; i++) {
        if (i == 0) {
            array[i] = 1;
        } else {
            array[i] = array[i-1] + i; // Introduce loop-carried RAW (read-after-write) dependency
        }
    }
    // Prevent dead code elimination and ensure side effect
    volatile uint64_t sink = array[loop_lim - 1];
    free(array);
}
