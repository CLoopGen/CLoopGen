#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_array;
extern double jellp1;
extern double jell;
extern double jellm1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (lmax >= 1) {
    for (ell = lmax; ell >= 1; ell--) {
        for (int unroll_factor = 1; unroll_factor <= 1; unroll_factor++) {
            jellm1 = -jellp1 + (2 * ell + 1) / x * jell;
            jellp1 = jell;
            jell = jellm1;
            result_array[ell - 1] = jellm1;
        }
    }
}
}
