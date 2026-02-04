#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by adjusting index usage
    // Instead of accessing in[i] and in[i-2], we shift the logic to use consecutive indices
    // Original loop runs i = 17, 15, 13, ..., 3
    // We now access in[i] and in[i-1], effectively changing stride pattern but maintaining similar data flow
    for (i = 16; i >= 2; i -= 2)
        in[i + 1] += in[i - 1];
}
