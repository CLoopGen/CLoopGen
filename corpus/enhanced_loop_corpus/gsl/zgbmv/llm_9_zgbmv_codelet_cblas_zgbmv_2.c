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
extern int L;
extern int U;
extern  double alpha_real;
extern  double alpha_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY && i < lenX; i++) {
    double dotR = 0.;
    double dotI = 0.;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = (i + U + 1 < lenX ? i + U + 1 : lenX);
    int ix_start = ((incX) > 0 ? 0 : (lenX - 1) * (-incX)) + j_min * incX;
    int offset_base = lda * i + L - i;
    for (j = j_min; j < j_max; j++) {
        const double x_val = ((const double*)X)[2 * ix_start];
        const double x_imag = ((const double*)X)[2 * ix_start + 1];
        const int a_index = 2 * (offset_base + j);
        const double A_val = ((const double*)A)[a_index];
        const double A_imag = ((const double*)A)[a_index + 1];

        double temp1 = A_val * x_val - A_imag * x_imag;
        double temp2 = A_val * x_imag + A_imag * x_val;
        dotR += temp1;
        dotI += temp2;

        ix_start += incX;
    }

    double y_real = ((double*)Y)[2 * iy];
    double y_imag = ((double*)Y)[2 * iy + 1];
    ((double*)Y)[2 * iy] = y_real + alpha_real * dotR - alpha_imag * dotI;
    ((double*)Y)[2 * iy + 1] = y_imag + alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
