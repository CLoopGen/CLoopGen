#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using array with stride of 2
    // Assuming hypothetical array 'data' accessed with stride to simulate non-consecutive access
    volatile size_t data[1024]; // Volatile to prevent optimization, simulate memory effect
    for (i = 0; i < K; i += 2) { // Outer loop with stride 2
        for (j = 0; j < i; j += 2) { // Inner loop with stride 2
            data[i] += data[j]; // Strided memory access pattern
        }
    }
}
