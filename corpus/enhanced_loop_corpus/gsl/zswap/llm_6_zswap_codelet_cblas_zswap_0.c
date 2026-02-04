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
    for (i = 0; i < N; i++) {
        const double tmp_real = x[2 * local_ix];
        const double tmp_imag = x[2 * local_ix + 1];
        x[2 * local_ix] = y[2 * local_iy];
        x[2 * local_ix + 1] = y[2 * local_iy + 1];
        y[2 * local_iy] = tmp_real;
        y[2 * local_iy + 1] = tmp_imag;
        local_ix += incX;
        local_iy += incY;
    }
}
