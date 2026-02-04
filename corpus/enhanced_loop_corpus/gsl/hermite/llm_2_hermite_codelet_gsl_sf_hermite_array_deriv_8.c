#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (j = 0; j <= nmax; j += stride) {
        if (j < nmax + 1)
            result_array[j] = 0.;
    }
}
