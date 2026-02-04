#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  int m;
extern  double x;
extern double *result_deriv_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = m; i <= lmax; i++) {
        ell = i;
        result_deriv_array[ell - m] = -0.25 * x * (ell - 1.) * ell * (ell + 1.) * (ell + 2.);
    }
}
