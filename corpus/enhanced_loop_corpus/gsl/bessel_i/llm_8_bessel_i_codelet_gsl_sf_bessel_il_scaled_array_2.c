#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ell = lmax; ell >= 1; ell--) {
        result_array[ell] = (double)(ell * ell + 2 * ell + 1) / 4.0;
    }
}
