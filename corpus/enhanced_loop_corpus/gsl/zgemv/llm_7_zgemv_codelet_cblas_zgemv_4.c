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
double acc_real = 0.0;
double acc_imag = 0.0;
for (j = 0; j < lenX; j++) {
    double x_real = (((const double *)X)[2 * (ix)]);
    double x_imag = (((const double *)X)[2 * (ix) + 1]);
    double tmpR = alpha_real * x_real - alpha_imag * x_imag;
    double tmpI = alpha_real * x_imag + alpha_imag * x_real;
    int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
    for (i = 0; i < lenY; i++) {
        const double A_real = (((const double *)A)[2 * (lda * j + i)]);
        const double A_imag = (((const double *)A)[2 * (lda * j + i) + 1]);
        acc_real += A_real * tmpR - (-A_imag) * tmpI;
        acc_imag += A_real * tmpI + (-A_imag) * tmpR;
        (((double *)Y)[2 * (iy)]) = acc_real;
        (((double *)Y)[2 * (iy) + 1]) = acc_imag;
        iy += incY;
    }
    acc_real = 0.0;
    acc_imag = 0.0;
    ix += incX;
}
}
