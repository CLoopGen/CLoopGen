#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern double r_real;
extern double r_imag;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        const double x_real_0 = (((const double *)X)[2 * (ix)]);
        const double x_imag_0 = (((const double *)X)[2 * (ix) + 1]);
        const double y_real_0 = (((const double *)Y)[2 * (iy)]);
        const double y_imag_0 = (((const double *)Y)[2 * (iy) + 1]);
        r_real += x_real_0 * y_real_0 - 1. * x_imag_0 * y_imag_0;
        r_imag += x_real_0 * y_imag_0 + 1. * x_imag_0 * y_real_0;
        ix += incX;
        iy += incY;

        if (i + 1 < N) {
            const double x_real_1 = (((const double *)X)[2 * (ix)]);
            const double x_imag_1 = (((const double *)X)[2 * (ix) + 1]);
            const double y_real_1 = (((const double *)Y)[2 * (iy)]);
            const double y_imag_1 = (((const double *)Y)[2 * (iy) + 1]);
            r_real += x_real_1 * y_real_1 - 1. * x_imag_1 * y_imag_1;
            r_imag += x_real_1 * y_imag_1 + 1. * x_imag_1 * y_real_1;
            ix += incX;
            iy += incY;
        }
    }
}
