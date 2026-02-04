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
    int ix = 0;
    const double* x_ptr = (const double*)X;
    const double* a_row_ptr = (const double*)A + 2 * (lda * i);
    for (j = 0; j < lenX; j++) {
        const double x_real = x_ptr[2 * ix];
        const double x_imag = x_ptr[2 * ix + 1];
        const double A_real = a_row_ptr[2 * j];
        const double A_imag = a_row_ptr[2 * j + 1];
        dotR += A_real * x_real - A_imag * x_imag;
        dotI += A_real * x_imag + A_imag * x_real;
        ix += incX;
    }
    double* y_ptr = (double*)Y + 2 * iy;
    y_ptr[0] += alpha_real * dotR - alpha_imag * dotI;
    y_ptr[1] += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
