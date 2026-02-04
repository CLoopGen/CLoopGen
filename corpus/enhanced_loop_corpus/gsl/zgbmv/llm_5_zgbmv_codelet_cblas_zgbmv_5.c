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
    const int j_min = (i >= L ? i - L : 0);
    const int j_max = (lenX <= i + U ? lenX : i + U + 1);
    if (j_min >= j_max) {
        iy += incY;
        continue;
    }
    int ix_start = ((incX) > 0 ? 0 : (lenX - 1) * (-incX));
    int ix = ix_start + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        const double x_real = (((const double *)X)[2 * ix]);
        const double x_imag = (((const double *)X)[2 * ix + 1]);
        const int a_idx = lda * i + (L + j - i);
        const double A_real = (((const double *)A)[2 * a_idx]);
        const double A_imag = (((const double *)A)[2 * a_idx + 1]);
        double temp_real = A_real * x_real + A_imag * x_imag;
        double temp_imag = A_real * x_imag - A_imag * x_real;
        dotR += temp_real;
        dotI += temp_imag;
        ix += incX;
    }
    double y_real = (((double *)Y)[2 * iy]);
    double y_imag = (((double *)Y)[2 * iy + 1]);
    y_real += alpha_real * dotR - alpha_imag * dotI;
    y_imag += alpha_real * dotI + alpha_imag * dotR;
    (((double *)Y)[2 * iy]) = y_real;
    (((double *)Y)[2 * iy + 1]) = y_imag;
    iy += incY;
}
}
