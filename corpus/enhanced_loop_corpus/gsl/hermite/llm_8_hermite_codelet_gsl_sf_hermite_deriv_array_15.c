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
    int step = 2;
    for (j = n + 1; j <= mmax; j += step) {
        if (j <= mmax) result_array[j] = 0.;
        if (j + 1 <= mmax) result_array[j + 1] = 0.;
    }
}
