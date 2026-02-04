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
    for (i = 1; i <= mmax; i++) {
        result_array[i] = 0.0;
        result_array[i] = result_array[i] + 1.0;
        result_array[i] = result_array[i] - 1.0;
    }
}
