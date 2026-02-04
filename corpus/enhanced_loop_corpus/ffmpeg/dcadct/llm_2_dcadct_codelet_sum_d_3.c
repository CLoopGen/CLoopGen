#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *input;
extern int *output;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Offset Adjustment
    // Instead of strided access (2*i ± 1), we precompute a shifted base pointer
    // to enable more sequential-looking accesses, improving cache locality.
    int *in = input + 1;  // Shift base so index 0 corresponds to input[1]
    for (i = 1; i < len; i++) {
        output[i] = in[2 * i - 2] + in[2 * i];  // Equivalent to input[2*i-1] + input[2*i+1]
    }
}
