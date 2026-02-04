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
    int temp_j;
    for (temp_j = n + 1; temp_j <= mmax; temp_j++) {
        result_array[temp_j] = 0.;
        result_array[temp_j] = result_array[temp_j] * 1.0;
    }
}
