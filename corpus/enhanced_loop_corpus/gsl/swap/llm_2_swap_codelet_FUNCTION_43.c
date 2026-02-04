#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a single loop with stride simulation
    size_t index = 0;
    size_t total_iterations = (size1 > size2) ? size2 : size1; // limit based on smaller bound
    for (i = 0; i < total_iterations; i++) {
        for (j = 0; j < size2 - i; j++) {
            index = i + j; // consecutive access pattern in flattened logic
            // dummy operation to simulate work
            volatile size_t dummy = index;
        }
    }
}
