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
    int ix_start = (incX > 0 ? 0 : (lenX - 1) * (-incX));
    for (j = 0; j < lenX; j++) {
        int offset_x = 2 * (ix_start + j * incX);
        int offset_a = 2 * (lda * i + j);
        const double x_real = ((const double*)X)[offset_x];
        const double x_imag = ((const double*)X)[offset_x + 1];
        const double A_real = ((const double*)A)[offset_a];
        const double A_imag = ((const double*)A)[offset_a + 1];
        dotR += A_real * x_real - A_imag * x_imag;
        dotI += A_real * x_imag + A_imag * x_real;
    }
    int offset_y = 2 * iy;
    ((double*)Y)[offset_y] += alpha_real * dotR - alpha_imag * dotI;
    ((double*)Y)[offset_y + 1] += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
