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
    for (n = nmax; n >= nmin; n -= 2) {
        result_array[n - nmin] = 0.;
        if (n - 1 >= nmin) {
            result_array[n - 1 - nmin] = 0.;
        }
    }
    if (nmin % 2 == 0 && nmin <= nmax && nmin == 0) {
        result_array[0] = 0.;
    }
}
