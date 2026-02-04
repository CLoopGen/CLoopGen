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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < M; i += 2) {
    int i1 = i;
    int i2 = i + 1;
    if (i2 >= M) break;

    const double X1_real = (((const double *)X)[2 * (ix)]);
    const double X1_imag = (((const double *)X)[2 * (ix) + 1]);
    const double X2_real = (((const double *)X)[2 * (ix + incX)]);
    const double X2_imag = (((const double *)X)[2 * (ix + incX) + 1]);

    const double tmp1_real = alpha_real * X1_real - alpha_imag * X1_imag;
    const double tmp1_imag = alpha_imag * X1_real + alpha_real * X1_imag;
    const double tmp2_real = alpha_real * X2_real - alpha_imag * X2_imag;
    const double tmp2_imag = alpha_imag * X2_real + alpha_real * X2_imag;

    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j < N; j++) {
        const double Y_real = (((const double *)Y)[2 * (jy)]);
        const double Y_imag = -(((const double *)Y)[2 * (jy) + 1]);

        // Update A[i1][j]
        (((double *)A)[2 * (lda * i1 + j)]) += Y_real * tmp1_real - Y_imag * tmp1_imag;
        (((double *)A)[2 * (lda * i1 + j) + 1]) += Y_imag * tmp1_real + Y_real * tmp1_imag;

        // Update A[i2][j]
        (((double *)A)[2 * (lda * i2 + j)]) += Y_real * tmp2_real - Y_imag * tmp2_imag;
        (((double *)A)[2 * (lda * i2 + j) + 1]) += Y_imag * tmp2_real + Y_real * tmp2_imag;

        jy += incY;
    }
    ix += 2 * incX;
}
}
