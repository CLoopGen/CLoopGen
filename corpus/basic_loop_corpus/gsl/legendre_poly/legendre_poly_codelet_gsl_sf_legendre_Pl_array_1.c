#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_array;
extern double p_ellm2;
extern double p_ellm1;
extern double p_ell;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ell = 2; ell <= lmax; ell++) {
    p_ell = (x * (2 * ell - 1) * p_ellm1 - (ell - 1) * p_ellm2) / ell;
    p_ellm2 = p_ellm1;
    p_ellm1 = p_ell;
    result_array[ell] = p_ell;
}

}
