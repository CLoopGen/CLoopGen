#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *X;
extern  int incX;
extern int i;
extern int ix;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        if (ix + incX < ((ptrdiff_t)N * incX)) {
            const double x_real1 = (((double *)X)[2 * (ix)]);
            const double x_imag1 = (((double *)X)[2 * (ix) + 1]);
            const double x_real2 = (((double *)X)[2 * (ix + incX)]);
            const double x_imag2 = (((double *)X)[2 * (ix + incX) + 1]);

            (((double *)X)[2 * (ix)]) = x_real1 * alpha_real - x_imag1 * alpha_imag;
            (((double *)X)[2 * (ix) + 1]) = x_real1 * alpha_imag + x_imag1 * alpha_real;
            (((double *)X)[2 * (ix + incX)]) = x_real2 * alpha_real - x_imag2 * alpha_imag;
            (((double *)X)[2 * (ix + incX) + 1]) = x_real2 * alpha_imag + x_imag2 * alpha_real;

            ix += 2 * incX;
        } else {
            const double x_real = (((double *)X)[2 * (ix)]);
            const double x_imag = (((double *)X)[2 * (ix) + 1]);
            (((double *)X)[2 * (ix)]) = x_real * alpha_real - x_imag * alpha_imag;
            (((double *)X)[2 * (ix) + 1]) = x_real * alpha_imag + x_imag * alpha_real;
            ix += incX;
        }
    }
}
