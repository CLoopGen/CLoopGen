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
    double prev_jellm1 = jellm1;
    for (ell = lmax; ell >= 1; ell--) {
        double computed_val = -jellp1 + (2 * ell + 1) / x * jell;
        result_array[ell - 1] = computed_val;
        jellp1 = jell;
        jell = computed_val;
        prev_jellm1 = computed_val;
    }
    jellm1 = prev_jellm1;
}
