#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern using a dummy array with stride of 2
    // Simulating memory access with stride to expose different cache behavior
    volatile int dummy_array[1024] = {0}; // Volatile to prevent optimization
    for (i = 0; i < K; i++) {
        for (j = 0; j < i; j += 2) { // Strided access: step by 2
            if (j < 1024) {
                dummy_array[j] += 1;
            }
        }
    }
}
