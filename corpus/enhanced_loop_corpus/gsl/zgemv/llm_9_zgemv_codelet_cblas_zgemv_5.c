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
for (i = 0; i < lenY; i += 2) {
    double dotR0 = 0., dotR1 = 0.;
    double dotI0 = 0., dotI1 = 0.;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    for (j = 0; j < lenX; j++) {
        const double x_real = (((const double *)X)[2 * (ix)]);
        const double x_imag = (((const double *)X)[2 * (ix) + 1]);
        const double A_real0 = (((const double *)A)[2 * (lda * i + j)]);
        const double A_imag0 = (((const double *)A)[2 * (lda * i + j) + 1]);
        const double A_real1 = (((const double *)A)[2 * (lda * (i+1) + j)]);
        const double A_imag1 = (((const double *)A)[2 * (lda * (i+1) + j) + 1]);
        dotR0 += A_real0 * x_real + A_imag0 * x_imag;
        dotI0 += A_real0 * x_imag - A_imag0 * x_real;
        dotR1 += A_real1 * x_real + A_imag1 * x_imag;
        dotI1 += A_real1 * x_imag - A_imag1 * x_real;
        ix += incX;
    }
    (((double *)Y)[2 * (iy)]) += alpha_real * dotR0 - alpha_imag * dotI0;
    (((double *)Y)[2 * (iy) + 1]) += alpha_real * dotI0 + alpha_imag * dotR0;
    iy += incY;
    if (i + 1 < lenY) {
        (((double *)Y)[2 * (iy)]) += alpha_real * dotR1 - alpha_imag * dotI1;
        (((double *)Y)[2 * (iy) + 1]) += alpha_real * dotI1 + alpha_imag * dotR1;
        iy += incY;
    }
}
}
