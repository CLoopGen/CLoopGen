#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    // Split into two independent loops to remove loop-carried dependencies
    for (j = 1; j <= mmax; j += stride) {
        result_array[j] = 0.0;
    }
    for (j = 2; j <= mmax; j += stride) {
        result_array[j] = 0.0;
    }
}
