#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern double ex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 1.0;
    for (i = 0; i <= nmax - nmin; i++) {
        temp *= ex;
        result_array[i] *= temp;
    }
}
