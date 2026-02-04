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
if (M <= 0 || N <= 0) return;
const int unroll_factor = 4;
for (j = 0; j < N; j++) {
    const double Y_real = (((const double *)Y)[2 * (jy)]);
    const double Y_imag = (((const double *)Y)[2 * (jy) + 1]);
    const double tmp_real = alpha_real * Y_real - alpha_imag * Y_imag;
    const double tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag;
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    i = 0;
    for (; i <= M - unroll_factor; i += unroll_factor) {
        const double X_real0 = (((const double *)X)[2 * (ix)]);
        const double X_imag0 = (((const double *)X)[2 * (ix) + 1]);
        const double X_real1 = (((const double *)X)[2 * (ix + incX)]);
        const double X_imag1 = (((const double *)X)[2 * (ix + incX) + 1]);
        const double X_real2 = (((const double *)X)[2 * (ix + 2*incX)]);
        const double X_imag2 = (((const double *)X)[2 * (ix + 2*incX) + 1]);
        const double X_real3 = (((const double *)X)[2 * (ix + 3*incX)]);
        const double X_imag3 = (((const double *)X)[2 * (ix + 3*incX) + 1]);

        (((double *)A)[2 * (i + lda * j)]) += X_real0 * tmp_real - X_imag0 * tmp_imag;
        (((double *)A)[2 * (i + lda * j) + 1]) += X_imag0 * tmp_real + X_real0 * tmp_imag;

        (((double *)A)[2 * (i+1 + lda * j)]) += X_real1 * tmp_real - X_imag1 * tmp_imag;
        (((double *)A)[2 * (i+1 + lda * j) + 1]) += X_imag1 * tmp_real + X_real1 * tmp_imag;

        (((double *)A)[2 * (i+2 + lda * j)]) += X_real2 * tmp_real - X_imag2 * tmp_imag;
        (((double *)A)[2 * (i+2 + lda * j) + 1]) += X_imag2 * tmp_real + X_real2 * tmp_imag;

        (((double *)A)[2 * (i+3 + lda * j)]) += X_real3 * tmp_real - X_imag3 * tmp_imag;
        (((double *)A)[2 * (i+3 + lda * j) + 1]) += X_imag3 * tmp_real + X_real3 * tmp_imag;

        ix += 4 * incX;
    }
    for (; i < M; i++) {
        const double X_real = (((const double *)X)[2 * (ix)]);
        const double X_imag = (((const double *)X)[2 * (ix) + 1]);
        (((double *)A)[2 * (i + lda * j)]) += X_real * tmp_real - X_imag * tmp_imag;
        (((double *)A)[2 * (i + lda * j) + 1]) += X_imag * tmp_real + X_real * tmp_imag;
        ix += incX;
    }
    jy += incY;
}
}
