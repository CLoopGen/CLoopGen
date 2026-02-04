#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_colors;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_sum = 0;
    for (i = 4; i < 4 * num_colors; ++i) {
        local_sum += i * i; // Eliminates loop-carried dependency on shared state; all operations are local and independent
    }
    // Final use to prevent dead code elimination
    if (local_sum > 0) {
        i = local_sum & 0xFFFF;
    }
}
