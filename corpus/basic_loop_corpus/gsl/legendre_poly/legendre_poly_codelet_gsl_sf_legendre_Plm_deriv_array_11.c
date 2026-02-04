#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  int m;
extern  double x;
extern double *result_array;
extern double *result_deriv_array;
extern int ell;
extern  double diff_a;
extern  double diff_b;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ell = m + 2; ell <= lmax; ell++) {
    result_deriv_array[ell - m] = -(ell * x * result_array[ell - m] - (ell + m) * result_array[ell - 1 - m]) / (diff_a * diff_b);
}

}
