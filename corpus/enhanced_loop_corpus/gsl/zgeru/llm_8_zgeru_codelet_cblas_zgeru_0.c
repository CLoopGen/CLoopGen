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
for (i = 0; i < M; i++) {
    const double X_real = (((const double *)X)[2 * (ix)]);
    const double X_imag = (((const double *)X)[2 * (ix) + 1]);
    const double tmp_real = alpha_real * X_real - alpha_imag * X_imag;
    const double tmp_imag = alpha_imag * X_real + alpha_real * X_imag;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j < N; j += 2) {
        if (j + 1 < N) {
            const double Y_real0 = (((const double *)Y)[2 * (jy)]);
            const double Y_imag0 = (((const double *)Y)[2 * (jy) + 1]);
            const double Y_real1 = (((const double *)Y)[2 * (jy + incY)]);
            const double Y_imag1 = (((const double *)Y)[2 * (jy + incY) + 1]);

            (((double *)A)[2 * (lda * i + j)]) += Y_real0 * tmp_real - Y_imag0 * tmp_imag;
            (((double *)A)[2 * (lda * i + j) + 1]) += Y_imag0 * tmp_real + Y_real0 * tmp_imag;

            (((double *)A)[2 * (lda * i + j + 1)]) += Y_real1 * tmp_real - Y_imag1 * tmp_imag;
            (((double *)A)[2 * (lda * i + j + 1) + 1]) += Y_imag1 * tmp_real + Y_real1 * tmp_imag;

            jy += 2 * incY;
        } else {
            const double Y_real0 = (((const double *)Y)[2 * (jy)]);
            const double Y_imag0 = (((const double *)Y)[2 * (jy) + 1]);
            (((double *)A)[2 * (lda * i + j)]) += Y_real0 * tmp_real - Y_imag0 * tmp_imag;
            (((double *)A)[2 * (lda * i + j) + 1]) += Y_imag0 * tmp_real + Y_real0 * tmp_imag;
            jy += incY;
        }
    }
    ix += incX;
}
}
