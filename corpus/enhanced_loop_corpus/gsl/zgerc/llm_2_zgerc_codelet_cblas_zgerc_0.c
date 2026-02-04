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
    for (j = 0; j < N; j++) {
        const double Y_real = (((const double *)Y)[2 * (jy)]);
        const double Y_imag = -(((const double *)Y)[2 * (jy) + 1]);
        const int a_idx = 2 * (lda * i + j);
        double *A_ptr = &(((double *)A)[a_idx]);
        A_ptr[0] += Y_real * tmp_real - Y_imag * tmp_imag;
        A_ptr[1] += Y_imag * tmp_real + Y_real * tmp_imag;
        jy += incY;
    }
    ix += incX;
}
}
