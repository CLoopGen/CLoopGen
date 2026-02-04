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
    int base_x = 2 * ix;
    double x_real = ((const double *)X)[base_x];
    double x_imag = ((const double *)X)[base_x + 1];
    double tmpR = alpha_real * x_real - alpha_imag * x_imag;
    double tmpI = alpha_real * x_imag + alpha_imag * x_real;
    int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
    const double* A_ptr = (const double*)A + 2 * lda * j;
    for (i = 0; i < lenY; i++) {
        const double A_real = A_ptr[2 * i];
        const double A_imag = A_ptr[2 * i + 1];
        int y_index = 2 * iy;
        ((double *)Y)[y_index] += A_real * tmpR - A_imag * tmpI;
        ((double *)Y)[y_index + 1] += A_real * tmpI + A_imag * tmpR;
        iy += incY;
    }
    ix += incX;
}
}
