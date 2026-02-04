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
if (M > 0 && N > 0) {
    for (int k = 0; k < M * N; k++) {
        const int i = k / N;
        const int j = k % N;
        const int ix_val = i * incX;
        const int jy_val = ((incY) > 0 ? 0 : (N - 1) * (-incY)) + j * incY;

        const double X_real = (((const double *)X)[2 * ix_val]);
        const double X_imag = (((const double *)X)[2 * ix_val + 1]);
        const double tmp_real = alpha_real * X_real - alpha_imag * X_imag;
        const double tmp_imag = alpha_imag * X_real + alpha_real * X_imag;

        const double Y_real = (((const double *)Y)[2 * jy_val]);
        const double Y_imag = -(((const double *)Y)[2 * jy_val + 1]);

        (((double *)A)[2 * (lda * i + j)]) += Y_real * tmp_real - Y_imag * tmp_imag;
        (((double *)A)[2 * (lda * i + j) + 1]) += Y_imag * tmp_real + Y_real * tmp_imag;
    }
}
}
