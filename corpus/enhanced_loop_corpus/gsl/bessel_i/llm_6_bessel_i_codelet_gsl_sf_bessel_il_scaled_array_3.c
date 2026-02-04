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
    double temp_iellp1 = iellp1;
    double temp_iell = iell;
    for (ell = lmax; ell >= 1; ell--) {
        double temp_iellm1 = temp_iellp1 + (2 * ell + 1) / x * temp_iell;
        temp_iellp1 = temp_iell;
        temp_iell = temp_iellm1;
        result_array[ell - 1] = temp_iellm1;
    }
    iellp1 = temp_iellp1;
    iell = temp_iell;
}
