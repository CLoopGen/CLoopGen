#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum = 0.0;
    for (ell = 0; ell <= lmax; ell++) {
        sum += (double)ell;
        result_array[ell] = sum / (ell + 1);
    }
}
