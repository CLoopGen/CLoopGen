#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int mmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= mmax; j++) {
        result_array[j] = 0.0;
        if (j > 1) {
            result_array[j] += result_array[j-1]; // Introduce RAW and loop-carried dependency
        }
    }
}
