#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int prefixes[18];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of sequential i from 1 to 16, use a stride of 2 and handle even indices only.
    // We still maintain the same logical operation but access elements with a step.
    for (i = 2; i <= 16; i += 2) {
        prefixes[i + 1] = (prefixes[i] + counts[i]) << 1;
        // Handle adjacent index if within bounds to preserve full coverage
        if (i - 1 >= 1) {
            prefixes[(i-1) + 1] = (prefixes[i-1] + counts[i-1]) << 1;
        }
    }
}
