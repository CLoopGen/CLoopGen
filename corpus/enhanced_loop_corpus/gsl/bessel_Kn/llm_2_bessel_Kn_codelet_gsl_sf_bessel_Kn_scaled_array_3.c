#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (j = 0; j <= nmax - nmin; j += 2)
        result_array[j] = 0.;
    // Handle odd-sized range if needed
    if ((nmax - nmin + 1) % 2 == 1 && j - 1 <= nmax - nmin)
        result_array[j - 1] = 0.;
}
