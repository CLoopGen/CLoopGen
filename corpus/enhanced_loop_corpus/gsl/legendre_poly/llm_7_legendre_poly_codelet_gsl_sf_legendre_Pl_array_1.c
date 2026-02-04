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
    double next_p_ellm1, next_p_ellm2;
    p_ell = (x * 3 * p_ellm1 - p_ellm2) / 2;
    result_array[2] = p_ell;
    if (lmax <= 2) return;
    next_p_ellm2 = p_ellm1;
    next_p_ellm1 = p_ell;
    for (ell = 3; ell <= lmax; ell++) {
        double updated_p_ell = (x * (2 * ell - 1) * next_p_ellm1 - (ell - 1) * next_p_ellm2) / ell;
        result_array[ell] = updated_p_ell;
        next_p_ellm2 = next_p_ellm1;
        next_p_ellm1 = updated_p_ell;
    }
    p_ellm2 = next_p_ellm2;
    p_ellm1 = next_p_ellm1;
    p_ell = next_p_ellm1;
}
