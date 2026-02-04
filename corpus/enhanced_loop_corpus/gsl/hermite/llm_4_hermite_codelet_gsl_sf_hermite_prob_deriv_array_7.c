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
    if (n >= mmax) return;
    for (j = n + 1; j <= mmax; j++) {
        result_array[j] = 0.;
    }
}
