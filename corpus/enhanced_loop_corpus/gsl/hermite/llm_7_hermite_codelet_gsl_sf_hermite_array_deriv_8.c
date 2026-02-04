#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_val = 0.0;
    for (j = 0; j <= nmax; j++) {
        result_array[j] = prev_val;
        prev_val = result_array[j] + 1.0;
    }
}
