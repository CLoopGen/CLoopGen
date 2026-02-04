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
        if (n - nmin >= 0) {
            result_array[n - nmin] = 0.;
        }
        if (n - 1 >= nmin) {
            result_array[n - 1 - nmin] = 0.;
        }
    }
    if ((nmax - nmin + 1) % 2 == 1 && nmin <= nmax) {
        result_array[0] = 0.;
    }
}
