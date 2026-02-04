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
    int limit = (nmax - nmin) & (~1); // Make it even for safe unrolling
    for (j = 0; j <= limit; j += stride) {
        result_array[j] = 0.;
        if (j + 1 <= limit) {
            result_array[j + 1] = 0.;
        }
    }
    // Handle remainder if any
    if ((nmax - nmin + 1) % 2 == 1) {
        result_array[nmax - nmin] = 0.;
    }
}
