#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev = 0.;
    for (j = 2; j <= mmax; j++) {
        result_array[j] = prev;
        prev = result_array[j];
    }
}
