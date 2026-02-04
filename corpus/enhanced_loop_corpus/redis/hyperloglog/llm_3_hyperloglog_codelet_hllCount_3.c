#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int reghisto[64];
extern double z;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with offset start, simulating reordered traversal
    const int start = 1;
    const int end = (64 - 14);
    for (j = start; j <= end; ++j) {
        int idx = end - j + start;  // Reverse index mapping to maintain similar data flow
        z += reghisto[idx];
        z *= 0.5;
    }
}
