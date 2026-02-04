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
    int stride = 2;
    int upper_bound = (nmax - nmin) / stride;
    for (j = 0; j <= upper_bound; j++) {
        result_array[j * stride] = 0.;
    }
}
