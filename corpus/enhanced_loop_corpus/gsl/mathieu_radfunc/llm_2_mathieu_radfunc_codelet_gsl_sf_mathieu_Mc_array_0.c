#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nmin;
extern int nmax;
extern double result_array[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (ii = 0; ii < nmax - nmin + 1; ii += 2) {
        result_array[ii] = 0.;
        if (ii + 1 < nmax - nmin + 1) {
            result_array[ii + 1] = 0.;
        }
    }
}
