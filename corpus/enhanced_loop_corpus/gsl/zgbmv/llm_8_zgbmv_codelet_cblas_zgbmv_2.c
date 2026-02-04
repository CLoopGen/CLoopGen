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
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j += 2) {
        const double x_real1 = (((const double *)X)[2 * (ix)]);
        const double x_imag1 = (((const double *)X)[2 * (ix) + 1]);
        const double A_real1 = (((const double *)A)[2 * (lda * i + (L + j - i))]);
        const double A_imag1 = (((const double *)A)[2 * (lda * i + (L + j - i)) + 1]);
        dotR += A_real1 * x_real1 - A_imag1 * x_imag1;
        dotI += A_real1 * x_imag1 + A_imag1 * x_real1;
        ix += incX;

        if (j + 1 < j_max) {
            const double x_real2 = (((const double *)X)[2 * (ix)]);
            const double x_imag2 = (((const double *)X)[2 * (ix) + 1]);
            const double A_real2 = (((const double *)A)[2 * (lda * i + (L + j + 1 - i))]);
            const double A_imag2 = (((const double *)A)[2 * (lda * i + (L + j + 1 - i)) + 1]);
            dotR += A_real2 * x_real2 - A_imag2 * x_imag2;
            dotI += A_real2 * x_imag2 + A_imag2 * x_real2;
            ix += incX;
        }
    }
    (((double *)Y)[2 * (iy)]) += alpha_real * dotR - alpha_imag * dotI;
    (((double *)Y)[2 * (iy) + 1]) += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
