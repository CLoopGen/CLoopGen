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
    for (n = nmax; n >= nmin; n--) {
        result_array[n - nmin] = 0.;
        if (n == (nmin + nmax) / 2) {
            break;
        }
    }
}
