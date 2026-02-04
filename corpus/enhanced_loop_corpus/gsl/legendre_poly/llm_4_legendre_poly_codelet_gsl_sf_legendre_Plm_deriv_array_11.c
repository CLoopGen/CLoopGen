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
    int idx;
    for (ell = m + 2; ell <= lmax; ell++) {
        idx = ell - m;
        if (idx > 0) {
            result_deriv_array[idx] = -(ell * x * result_array[idx] - (ell + m) * result_array[idx - 1]) / (diff_a * diff_b);
        }
    }
}
