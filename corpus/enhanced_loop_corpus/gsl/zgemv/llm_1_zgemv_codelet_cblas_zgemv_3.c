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
    int iy_base = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
    for (i = 0; i < lenY; i++) {
        int offset_A = 2 * (lda * j + i);
        int offset_Y = 2 * (iy_base + i * incY);
        const double A_real = (((const double *)A)[offset_A]);
        const double A_imag = (((const double *)A)[offset_A + 1]);
        (((double *)Y)[offset_Y]) += A_real * tmpR - A_imag * tmpI;
        (((double *)Y)[offset_Y + 1]) += A_real * tmpI + A_imag * tmpR;
    }
    ix += incX;
}
}
