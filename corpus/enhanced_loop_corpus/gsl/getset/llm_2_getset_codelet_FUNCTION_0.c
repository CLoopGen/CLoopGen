#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < N; j += 2) {
        unsigned int k;
        // Simulate strided memory access pattern by skipping every other index
        // This modifies the access pattern to non-consecutive, stride-2
    }
}
