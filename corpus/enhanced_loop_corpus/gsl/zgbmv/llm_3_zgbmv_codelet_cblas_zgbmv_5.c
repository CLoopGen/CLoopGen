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
for (i = 0; i < lenY; i++) {
    double dotR = 0.;
    double dotI = 0.;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    int base_A_offset = lda * i + L;
    int ix_start = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    for (j = j_min; j < j_max; j++) {
        int offset_X = 2 * (ix_start + j * incX);
        int offset_A = 2 * (base_A_offset + j - i);
        const double x_real = ((const double*)X)[offset_X];
        const double x_imag = ((const double*)X)[offset_X + 1];
        const double A_real = ((const double*)A)[offset_A];
        const double A_imag = ((const double*)A)[offset_A + 1];
        dotR += A_real * x_real + A_imag * x_imag;
        dotI += A_real * x_imag - A_imag * x_real;
    }
    int offset_Y = 2 * iy;
    ((double*)Y)[offset_Y]     += alpha_real * dotR - alpha_imag * dotI;
    ((double*)Y)[offset_Y + 1] += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
