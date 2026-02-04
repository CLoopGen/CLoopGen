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
    for (n = nmin; n <= nmax; n++) {
        if (n == nmin) {
            result_array[0] = 0.0;
        } else {
            result_array[n - nmin] = result_array[n - nmin - 1] + 1.0;
        }
    }
}
