#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_deriv_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const double inv4 = 0.25;
for (ell = 2; ell <= lmax; ell++) {
    const double epllus1 = ell + 1.;
    const double eplus2 = ell + 2.;
    const double eminus1 = ell - 1.;
    const double temp1 = (1. - x) * eplus2 * eminus1;
    const double temp2 = inv4 * temp1;
    const double pre = 0.5 * ell * epllus1;
    result_deriv_array[ell] = pre * (1. - temp2);
}
}
