#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ell = 0; ell <= lmax; ell += 2) {
        result_array[ell] = 0.;
        if (ell + 1 <= lmax)
            result_array[ell + 1] = 0.;
    }
}
