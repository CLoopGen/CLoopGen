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
    double acc_real = r_real;
    double acc_imag = r_imag;
    for (i = 0; i < N; i++) {
        const double x_real = (((const double *)X)[2 * (ix + i * incX)]);
        const double x_imag = (((const double *)X)[2 * (ix + i * incX) + 1]);
        const double y_real = (((const double *)Y)[2 * (iy + i * incY)]);
        const double y_imag = (((const double *)Y)[2 * (iy + i * incY) + 1]);
        const double product_real = x_real * y_real - x_imag * y_imag;
        const double product_imag = x_real * y_imag + x_imag * y_real;
        acc_real = acc_real + product_real;
        acc_imag = acc_imag + product_imag;
    }
    r_real = acc_real;
    r_imag = acc_imag;
    ix += N * incX;
    iy += N * incY;
}
