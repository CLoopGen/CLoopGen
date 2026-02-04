#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern double ex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in a strided pattern)
    int stride = 2;
    for (i = 0; i <= nmax - nmin; i += stride) {
        if (i <= nmax - nmin) {
            result_array[i] *= ex;
        }
    }
}
