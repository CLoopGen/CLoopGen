#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  int m;
extern double *result_deriv_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ell = m; ell <= lmax; ell++) {
        if (ell >= m) {
            result_deriv_array[ell - m] = 0.;
        }
    }
}
