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
double prev_tmp_real = 0.0;
double prev_tmp_imag = 0.0;
for (i = 0; i < M; i++) {
    const double X_real = (((const double *)X)[2 * (ix)]);
    const double X_imag = (((const double *)X)[2 * (ix) + 1]);
    const double tmp_real = alpha_real * X_real - alpha_imag * X_imag + prev_tmp_real;
    const double tmp_imag = alpha_imag * X_real + alpha_real * X_imag + prev_tmp_imag;
    prev_tmp_real = tmp_real * 0.1;
    prev_tmp_imag = tmp_imag * 0.1;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j < N; j++) {
        const double Y_real = (((const double *)Y)[2 * (jy)]);
        const double Y_imag = -(((const double *)Y)[2 * (jy) + 1]);
        const int a_idx = 2 * (lda * i + j);
        ((double*)A)[a_idx] = Y_real * tmp_real - Y_imag * tmp_imag;
        ((double*)A)[a_idx + 1] = Y_imag * tmp_real + Y_real * tmp_imag;
        jy += incY;
    }
    ix += incX;
}
}
