#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  void *A;
extern  int lda;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern  double alpha_real;
extern  double alpha_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i++) {
    double dotR = 0.;
    double dotI = 0.;
    int ix_start = (incX > 0) ? 0 : (lenX - 1) * (-incX);
    int j_end = lenX;
    for (j = 0; j < j_end; j++) {
        int ix = ix_start + j * incX;
        const double x_real = (((const double *)X)[2 * ix]);
        const double x_imag = (((const double *)X)[2 * ix + 1]);
        const double A_real = (((const double *)A)[2 * (lda * i + j)]);
        const double A_imag = (((const double *)A)[2 * (lda * i + j) + 1]);
        if (A_real != 0.0 || A_imag != 0.0 || x_real != 0.0 || x_imag != 0.0) {
            dotR += A_real * x_real - A_imag * x_imag;
            dotI += A_real * x_imag + A_imag * x_real;
        }
    }
    double yr = (((double *)Y)[2 * iy]);
    double yi = (((double *)Y)[2 * iy + 1]);
    double outR = alpha_real * dotR - alpha_imag * dotI;
    double outI = alpha_real * dotI + alpha_imag * dotR;
    if (outR != 0.0 || outI != 0.0) {
        yr += outR;
        yi += outI;
    }
    (((double *)Y)[2 * iy]) = yr;
    (((double *)Y)[2 * iy + 1]) = yi;
    iy += incY;
}
}
