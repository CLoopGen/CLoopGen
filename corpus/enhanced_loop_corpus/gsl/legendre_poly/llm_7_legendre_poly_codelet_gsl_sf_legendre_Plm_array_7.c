#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  int m;
extern  double x;
extern double *result_array;
extern double p_ellm2;
extern double p_ellm1;
extern double p_ell;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double next_p_ellm2, next_p_ellm1;
    double local_p_ell = p_ell;
    double local_p_ellm1 = p_ellm1;
    double local_p_ellm2 = p_ellm2;

    for (ell = m + 2; ell <= lmax; ell++) {
        local_p_ell = (x * (2. * ell - 1.) * local_p_ellm1 - (ell + m - 1) * local_p_ellm2) / (ell - m);
        result_array[ell - m] = local_p_ell;

        next_p_ellm2 = local_p_ellm1;
        next_p_ellm1 = local_p_ell;

        local_p_ellm2 = next_p_ellm2;
        local_p_ellm1 = next_p_ellm1;
    }

    p_ellm2 = local_p_ellm2;
    p_ellm1 = local_p_ellm1;
    p_ell = local_p_ell;
}
