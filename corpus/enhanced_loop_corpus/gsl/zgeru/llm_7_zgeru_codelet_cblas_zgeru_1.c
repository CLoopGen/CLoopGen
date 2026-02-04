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
double temp_accum_real[64];
double temp_accum_imag[64];
for (j = 0; j < N; j++) {
    const double Y_real = (((const double *)Y)[2 * (jy)]);
    const double Y_imag = (((const double *)Y)[2 * (jy) + 1]);
    const double tmp_real = alpha_real * Y_real - alpha_imag * Y_imag;
    const double tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag;
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M && i < 64; i++) {
        const double X_real = (((const double *)X)[2 * (ix)]);
        const double X_imag = (((const double *)X)[2 * (ix) + 1]);
        temp_accum_real[i] = X_real * tmp_real - X_imag * tmp_imag;
        temp_accum_imag[i] = X_imag * tmp_real + X_real * tmp_imag;
        ix += incX;
    }
    for (i = 0; i < M && i < 64; i++) {
        ((double *)A)[2 * (i + lda * j)] += temp_accum_real[i];
        ((double *)A)[2 * (i + lda * j) + 1] += temp_accum_imag[i];
    }
    jy += incY;
}
}
