#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_j, step = 2;
    // Unroll and eliminate loop-carried dependency by processing independent indices
    // Split the loop into even and odd index handling to remove potential dependencies
    for (local_j = 2; local_j <= mmax; local_j += step) {
        if (local_j <= mmax)
            result_array[local_j] = 0.;
        if (local_j + 1 <= mmax)
            result_array[local_j + 1] = 0.;
    }
    // Final cleanup if mmax is odd and loop boundary requires it
    if (mmax % 2 == 1 && mmax >= 2) {
        result_array[mmax] = 0.;
    }
}
