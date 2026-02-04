#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (j = 0; j <= nmax - nmin; j += stride) {
        if (j <= nmax - nmin) {
            result_array[j] = 0.;
        }
    }
    // Handle any potential odd-sized range if stride skips last element
    if ((nmax - nmin + 1) % 2 == 1) {
        result_array[nmax - nmin] = 0.;
    }
}
