#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_array;
extern int ell;
extern double iellp1;
extern double iell;
extern double iellm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ell = lmax; ell >= 1; ell--) {
        if (x != 0.0) {
            iellm1 = iellp1 + (2 * ell + 1) / x * iell;
            iellp1 = iell;
            iell = iellm1;
            result_array[ell - 1] = iellm1;
        }
    }
}
