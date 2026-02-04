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
    double prev_val = 1.0;
    for (n = nmax; n >= nmin; n--) {
        result_array[n - nmin] = prev_val * 2.0; // Introduce loop-carried dependence (RAW): current depends on previous iteration
        prev_val = result_array[n - nmin];
    }
}
