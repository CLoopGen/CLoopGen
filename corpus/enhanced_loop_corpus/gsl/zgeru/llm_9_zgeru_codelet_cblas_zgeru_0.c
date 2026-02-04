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
for (i = 0; i < M && M > 0; i++) {
    const double X_real = (((const double *)X)[2 * (ix)]);
    const double X_imag = (((const double *)X)[2 * (ix) + 1]);
    const double tmp_real = alpha_real * X_real;
    const double tmp_imag = alpha_real * X_imag;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j < N; j++) {
        const double Y_real = (((const double *)Y)[2 * (jy)]);
        const double Y_imag = (((const double *)Y)[2 * (jy) + 1]);
        double a_real = (((double *)A)[2 * (lda * i + j)]);
        double a_imag = (((double *)A)[2 * (lda * i + j) + 1]);
        a_real += Y_real * tmp_real;
        a_imag += Y_real * tmp_imag;
        (((double *)A)[2 * (lda * i + j)]) = a_real;
        (((double *)A)[2 * (lda * i + j) + 1]) = a_imag;
        jy += incY;
    }
    ix += incX;
}
}
