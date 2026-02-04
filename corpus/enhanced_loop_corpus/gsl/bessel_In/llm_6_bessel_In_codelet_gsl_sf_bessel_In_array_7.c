#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;
extern double eax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = eax;
    for (j = 1; j <= nmax - nmin; j++) {
        result_array[j] *= result_array[j-1];
    }
    if ((nmax - nmin) >= 0)
        result_array[0] *= temp;
}
