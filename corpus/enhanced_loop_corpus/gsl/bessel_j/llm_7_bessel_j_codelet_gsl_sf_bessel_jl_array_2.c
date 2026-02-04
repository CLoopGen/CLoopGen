#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (j = 1; j <= lmax; j++) {
        temp += result_array[j];
        result_array[j] = temp;
    }
    for (j = 1; j <= lmax; j++) {
        result_array[j] -= temp / lmax;
    }
}
