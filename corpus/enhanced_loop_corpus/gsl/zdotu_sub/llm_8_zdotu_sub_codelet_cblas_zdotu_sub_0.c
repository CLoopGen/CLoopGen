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
        if (i + 1 < N) {
            const double x1_real = (((const double *)X)[2 * (ix)]);
            const double x1_imag = (((const double *)X)[2 * (ix) + 1]);
            const double y1_real = (((const double *)Y)[2 * (iy)]);
            const double y1_imag = (((const double *)Y)[2 * (iy) + 1]);
            const double x2_real = (((const double *)X)[2 * (ix + incX)]);
            const double x2_imag = (((const double *)X)[2 * (ix + incX) + 1]);
            const double y2_real = (((const double *)Y)[2 * (iy + incY)]);
            const double y2_imag = (((const double *)Y)[2 * (iy + incY) + 1]);

            r_real += x1_real * y1_real - 1. * x1_imag * y1_imag +
                      x2_real * y2_real - 1. * x2_imag * y2_imag;
            r_imag += x1_real * y1_imag + 1. * x1_imag * y1_real +
                      x2_real * y2_imag + 1. * x2_imag * y2_real;
            ix += 2 * incX;
            iy += 2 * incY;
        } else {
            const double x_real = (((const double *)X)[2 * (ix)]);
            const double x_imag = (((const double *)X)[2 * (ix) + 1]);
            const double y_real = (((const double *)Y)[2 * (iy)]);
            const double y_imag = (((const double *)Y)[2 * (iy) + 1]);
            r_real += x_real * y_real - 1. * x_imag * y_imag;
            r_imag += x_real * y_imag + 1. * x_imag * y_real;
            ix += incX;
            iy += incY;
        }
    }
}
