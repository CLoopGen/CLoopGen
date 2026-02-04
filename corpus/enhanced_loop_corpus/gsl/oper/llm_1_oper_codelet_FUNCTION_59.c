#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (linearized) memory access pattern
    // Traverse all elements in a linear, consecutive order as if flattening a 2D structure
    size_t idx = 0;
    for (i = 0; i < M * N; i++) {
        idx = i;  // Direct sequential index
        // Simulated use of idx to represent consecutive access
        volatile size_t use = idx;
        (void)use;
    }
}
