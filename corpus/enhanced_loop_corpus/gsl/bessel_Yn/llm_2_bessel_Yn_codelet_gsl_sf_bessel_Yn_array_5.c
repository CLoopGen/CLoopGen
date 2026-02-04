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
    // Variant 1: Strided memory access with step size of 2
    for (int i = nmin; i <= nmax; i += 2) {
        result_array[i - nmin] = 0.;
        if (i + 1 <= nmax) {
            result_array[i + 1 - nmin] = 0.;
        }
    }
}
