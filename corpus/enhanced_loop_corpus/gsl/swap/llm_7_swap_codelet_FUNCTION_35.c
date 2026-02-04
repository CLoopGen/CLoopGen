#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_array[64]; // Local array to enable independent computations
    for (p = 0; p < size1; p++) {
        size_t k = p % 64;
        size_t n = p + 5; 
        temp_array[k] = n * 2; // Write to local array with index based on p
        // No loop-carried dependencies: each iteration is independent (parallelizable)
    }
    // Use temp_array to prevent optimization away
    volatile size_t sink = temp_array[0];
}
