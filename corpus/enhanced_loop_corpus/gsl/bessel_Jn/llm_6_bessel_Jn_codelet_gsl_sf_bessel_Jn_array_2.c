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
        temp = result_array[n - nmin]; // Introduce RAW dependency: read before write
        result_array[n - nmin] = temp + 0.; // WAW removed, but now has loop-carried flow via temp (artificially introduced)
    }
}
