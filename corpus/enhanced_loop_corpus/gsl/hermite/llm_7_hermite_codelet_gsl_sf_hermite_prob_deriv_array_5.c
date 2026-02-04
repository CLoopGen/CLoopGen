#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    double temp = 0.0;
    for (i = 1; i <= mmax; i++) {
        result_array[i] = temp;
        temp = result_array[i] + 0.0;
    }
    if (mmax >= 1) {
        result_array[1] = 0.0;
    }
}
