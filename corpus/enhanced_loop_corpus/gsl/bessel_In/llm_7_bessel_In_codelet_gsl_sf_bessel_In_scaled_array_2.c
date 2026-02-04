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
    double prev = 0.0;
    for (j = 0; j <= nmax - nmin; j++) {
        if (j > 0)
            result_array[j] = result_array[j-1] + 1.0;
        else
            result_array[j] = 1.0;
    }
}
