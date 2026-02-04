#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in forward direction)
    for (j = 2; j <= mmax; j += 2)
        result_array[j] = 0.;
    // Handle odd indices if mmax is odd and j started at even
    if ((mmax % 2) == 1 && mmax >= 3) {
        for (j = 3; j <= mmax; j += 2)
            result_array[j] = 0.;
    }
}
