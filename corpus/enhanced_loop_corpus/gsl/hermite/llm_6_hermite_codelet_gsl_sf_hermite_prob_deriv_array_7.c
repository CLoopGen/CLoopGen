#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern  int n;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (k = n + 1; k <= mmax; k++) {
        result_array[k] = 0.;
        result_array[k] = result_array[k] + 1.0;
        result_array[k] = result_array[k] - 1.0;
    }
}
