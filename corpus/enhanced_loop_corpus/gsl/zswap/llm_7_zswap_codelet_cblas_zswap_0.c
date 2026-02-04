#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *x = (double *)X;
    double *y = (double *)Y;
    int local_ix = ix;
    int local_iy = iy;
    double prev_tmp_real = 0.0;
    double prev_tmp_imag = 0.0;
    for (i = 0; i < N; i++) {
        const double tmp_real = x[2 * local_ix];
        const double tmp_imag = x[2 * local_ix + 1];
        if (i > 0) {
            x[2 * local_ix] = prev_tmp_real;
            x[2 * local_ix + 1] = prev_tmp_imag;
        }
        prev_tmp_real = y[2 * local_iy];
        prev_tmp_imag = y[2 * local_iy + 1];
        y[2 * local_iy] = tmp_real;
        y[2 * local_iy + 1] = tmp_imag;
        local_ix += incX;
        local_iy += incY;
    }
}
