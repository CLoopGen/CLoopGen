#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double *result_array;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed indexing
    // Instead of accessing result_array from high to low index,
    // we reverse the loop order and access consecutively from start to end.
    int range = nmax - nmin + 1;
    for (n = nmin; n <= nmax; n++) {
        result_array[n - nmin] = 0.;
    }
}
