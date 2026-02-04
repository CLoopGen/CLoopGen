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
    if (ell - m < (lmax - m + 1)) {
        result_deriv_array[ell - m] = 0.;
    } else {
        continue;
    }
}
}
