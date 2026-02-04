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
for (int phase = 0; phase < 2; phase++) {
    int start = (phase == 0) ? 2 : ((lmax / 2) + 1);
    int end   = (phase == 0) ? (lmax / 2) : lmax;
    for (ell = start; ell <= end; ell++) {
        const double pre = 0.5 * ell * (ell + 1.);
        result_deriv_array[ell] = pre * (1. - 0.25 * (1. - x) * (ell + 2.) * (ell - 1.));
    }
}
}
