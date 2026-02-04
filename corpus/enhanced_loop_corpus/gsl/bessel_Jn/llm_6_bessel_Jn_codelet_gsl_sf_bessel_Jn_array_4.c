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
    double temp = 0.0;
    for (n = nmax; n >= nmin; n--) {
        temp = 0.;
        result_array[n - nmin] = temp;
    }
}
