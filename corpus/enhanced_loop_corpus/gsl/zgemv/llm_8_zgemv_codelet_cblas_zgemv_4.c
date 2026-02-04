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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < lenX; j += 2) {
    if (j + 1 >= lenX) break;
    double x_real0 = (((const double *)X)[2 * (ix)]);
    double x_imag0 = (((const double *)X)[2 * (ix) + 1]);
    double x_real1 = (((const double *)X)[2 * (ix + incX)]);
    double x_imag1 = (((const double *)X)[2 * (ix + incX) + 1]);
    double tmpR0 = alpha_real * x_real0 - alpha_imag * x_imag0;
    double tmpI0 = alpha_real * x_imag0 + alpha_imag * x_real0;
    double tmpR1 = alpha_real * x_real1 - alpha_imag * x_imag1;
    double tmpI1 = alpha_real * x_imag1 + alpha_imag * x_real1;
    int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
    for (i = 0; i < lenY; i++) {
        const double A_real0 = (((const double *)A)[2 * (lda * j + i)]);
        const double A_imag0 = (((const double *)A)[2 * (lda * j + i) + 1]);
        const double A_real1 = (((const double *)A)[2 * (lda * (j + 1) + i)]);
        const double A_imag1 = (((const double *)A)[2 * (lda * (j + 1) + i) + 1]);
        (((double *)Y)[2 * (iy)]) += A_real0 * tmpR0 - (-A_imag0) * tmpI0 +
                                      A_real1 * tmpR1 - (-A_imag1) * tmpI1;
        (((double *)Y)[2 * (iy) + 1]) += A_real0 * tmpI0 + (-A_imag0) * tmpR0 +
                                          A_real1 * tmpI1 + (-A_imag1) * tmpR1;
        iy += incY;
    }
    ix += 2 * incX;
}
}
