#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t* array = (uint64_t*)malloc(src_size1 * sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < src_size1; i++) {
        if (i == 0) {
            array[i] = 1;
        } else {
            array[i] = array[i-1] + i; // Introduce loop-carried RAW (read-after-write) dependency
        }
    }
    // Prevent unused variable warning and ensure side-effect visibility
    volatile uint64_t sink = array[src_size1 - 1];
    free(array);
}
