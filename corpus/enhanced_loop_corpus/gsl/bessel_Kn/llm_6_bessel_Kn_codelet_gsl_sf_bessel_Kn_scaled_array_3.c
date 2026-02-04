#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (j = 0; j <= nmax - nmin; j++) {
        result_array[j] = temp;
        temp = result_array[j] + 1.0;
    }
}
