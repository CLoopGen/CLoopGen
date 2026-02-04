#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j <= nmax; j += 2) {
        if (j <= nmax) result_array[j] = 0.;
        if (j + 1 <= nmax) result_array[j + 1] = 0.;
    }
}
