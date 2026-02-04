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
    int stride = 2;
    for (j = 0; j <= nmax - nmin; j += stride) {
        if (j <= nmax - nmin) {
            result_array[j] = 0.;
        }
    }
    // Handle last element if range is odd and not covered by strided access
    if ((nmax - nmin + 1) % stride != 0 && (nmax - nmin) > 0) {
        result_array[nmax - nmin] = 0.;
    }
}
