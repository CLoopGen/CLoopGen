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
for (j = 0; j < lenX; j++) {
    double x_real = (((const double *)X)[2 * (ix)]);
    double x_imag = (((const double *)X)[2 * (ix) + 1]);
    double tmpR = alpha_real * x_real - alpha_imag * x_imag;
    double tmpI = alpha_real * x_imag + alpha_imag * x_real;
    int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
    for (i = 0; i < lenY; i += 2) {
        if (i + 1 >= lenY) {
            const double A_real = (((const double *)A)[2 * (lda * j + i)]);
            const double A_imag = (((const double *)A)[2 * (lda * j + i) + 1]);
            (((double *)Y)[2 * (iy)]) += A_real * tmpR - (-A_imag) * tmpI;
            (((double *)Y)[2 * (iy) + 1]) += A_real * tmpI + (-A_imag) * tmpR;
            break;
        }
        const double A_real0 = (((const double *)A)[2 * (lda * j + i)]);
        const double A_imag0 = (((const double *)A)[2 * (lda * j + i) + 1]);
        const double A_real1 = (((const double *)A)[2 * (lda * j + i + 1)]);
        const double A_imag1 = (((const double *)A)[2 * (lda * j + i + 1) + 1]);
        (((double *)Y)[2 * (iy)]) += A_real0 * tmpR - (-A_imag0) * tmpI;
        (((double *)Y)[2 * (iy) + 1]) += A_real0 * tmpI + (-A_imag0) * tmpR;
        iy += incY;
        (((double *)Y)[2 * (iy)]) += A_real1 * tmpR - (-A_imag1) * tmpI;
        (((double *)Y)[2 * (iy) + 1]) += A_real1 * tmpI + (-A_imag1) * tmpR;
        iy += incY;
    }
    ix += incX;
}
}
