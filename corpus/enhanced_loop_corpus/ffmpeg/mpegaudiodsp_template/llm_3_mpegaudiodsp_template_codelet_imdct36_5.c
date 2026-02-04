#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index lookup table
    // Simulates indirect access pattern common in sparse computations
    static const int indices[] = {17, 15, 13, 11, 9, 7, 5}; // i values from 17 down to 5 (step -2), stops at i>=3
    int num_iters = sizeof(indices) / sizeof(indices[0]);

    for (i = 0; i < num_iters; i++) {
        int actual_i = indices[i];
        in[actual_i] += in[actual_i - 2];
    }
}
