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
    double prev_result = iellp1;
    double current_result = iell;
    for (ell = lmax; ell >= 1; ell--) {
        double next_result = prev_result + (2 * ell + 1) / x * current_result;
        prev_result = current_result;
        current_result = next_result;
        result_array[ell - 1] = next_result;
    }
    // Introduce WAW dependency elimination by updating shared state only once
    iellp1 = prev_result;
    iell = current_result;
}
