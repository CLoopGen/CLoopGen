#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using a dummy array with stride of 2
    // Assuming a flat array access pattern with stride to mimic non-consecutive memory accesses
    volatile size_t dummy_array[1024]; // Volatile to prevent optimization
    for (i = 0; i < K; i++) {
        for (j = 0; j < i; j += 2) { // Strided access: increment by 2
            if ((j * i) % 2 == 0) {
                dummy_array[(j * i) % 1024]++; // Simulate strided memory write
            }
        }
    }
}
