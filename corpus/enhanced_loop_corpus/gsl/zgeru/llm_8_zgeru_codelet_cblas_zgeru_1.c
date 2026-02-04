#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern void *A;
extern  int lda;
extern int i;
extern int j;
extern  double alpha_real;
extern  double alpha_imag;
extern int jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < N; j += 2) {
    const double Y_real0 = (((const double *)Y)[2 * (jy)]);
    const double Y_imag0 = (((const double *)Y)[2 * (jy) + 1]);
    const double tmp_real0 = alpha_real * Y_real0 - alpha_imag * Y_imag0;
    const double tmp_imag0 = alpha_imag * Y_real0 + alpha_real * Y_imag0;
    const double Y_real1 = (j + 1 < N) ? (((const double *)Y)[2 * (jy + incY)]) : 0.0;
    const double Y_imag1 = (j + 1 < N) ? (((const double *)Y)[2 * (jy + incY) + 1]) : 0.0;
    const double tmp_real1 = alpha_real * Y_real1 - alpha_imag * Y_imag1;
    const double tmp_imag1 = alpha_imag * Y_real1 + alpha_real * Y_imag1;
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M; i++) {
        const double X_real = (((const double *)X)[2 * (ix)]);
        const double X_imag = (((const double *)X)[2 * (ix) + 1]);
        (((double *)A)[2 * (i + lda * j)]) += X_real * tmp_real0 - X_imag * tmp_imag0;
        (((double *)A)[2 * (i + lda * j) + 1]) += X_imag * tmp_real0 + X_real * tmp_imag0;
        if (j + 1 < N) {
            (((double *)A)[2 * (i + lda * (j + 1))]) += X_real * tmp_real1 - X_imag * tmp_imag1;
            (((double *)A)[2 * (i + lda * (j + 1)) + 1]) += X_imag * tmp_real1 + X_real * tmp_imag1;
        }
        ix += incX;
    }
    jy += 2 * incY;
}
}
