#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t arr[1027];
    for (i = 0; i < 1027; i++) {
        if (i == 0) {
            arr[i] = 1;
        } else {
            arr[i] = arr[i-1] + i; // Loop-carried RAW dependency: current depends on previous
        }
    }
    // Eliminate direct scalar WAW on shared variables but introduce array-based
    // loop-carried dependency. Each iteration depends on the result of the prior.
    // This creates a sequential data flow that prevents parallelization.
}
