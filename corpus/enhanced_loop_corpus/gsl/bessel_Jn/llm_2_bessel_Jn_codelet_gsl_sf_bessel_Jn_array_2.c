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
    // Variant 1: Strided memory access (access every 2nd element in reverse, then handle remainder)
    int stride = 2;
    // First pass: strided access
    for (n = nmax; n >= nmin; n -= stride) {
        result_array[n - nmin] = 0.;
    }
    // Second pass: fill in the skipped elements
    for (n = nmax - 1; n >= nmin; n -= stride) {
        result_array[n - nmin] = 0.;
    }
}
