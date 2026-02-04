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
    double prev = 0.0;
    for (n = nmax; n >= nmin; n--) {
        result_array[n - nmin] = prev;
        prev += 1.0;
    }
}
