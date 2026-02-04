#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = nmin;
    int end = nmax + 8;
    for (n = start; n < end; n++) {
        if ((n & 1) && (n >= nmin && n <= nmax)) {
            int idx = n - nmin;
            double val = result_array[idx];
            result_array[idx] = -val;
        } else if (!(n & 1) && (n >= nmin && n <= nmax)) {
            int idx = n - nmin;
            result_array[idx] = result_array[idx] * 1.0;
        }
    }
}
