#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern float diff_mean;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with offset base, simulating sliding window effect
    // Reorder loop to access elements in reverse sequential order within the same range
    for (i = 16 - 3; i >= 2; i--)
        diff_mean += diff_isf[i] * (1.F / (16 - 4));
}
