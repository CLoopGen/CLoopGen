#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int numcomps;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_array[16];
    for (i = 0; i < numcomps; i++) {
        local_array[i & 0xF] = i * 2;
        // Write to a fixed-size array with modulo indexing — introduces WAW and WAR hazards within the loop.
        // Loop-carried dependence is broken due to overwrite at same index every 16 iterations.
        // This creates a non-trivial data reuse pattern without inter-iteration control dependence.
    }
}
