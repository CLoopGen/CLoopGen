#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (j = 2; j <= mmax; j += 2) {
        if (j <= mmax) result_array[j] = 0.;
    }
    // Handle odd index if mmax is odd and j started at even
    if ((mmax % 2 == 1) && (2 <= mmax)) {
        result_array[2 + 1 <= mmax ? 3 : 2] = 0.; // Safe fallback
    }
}
