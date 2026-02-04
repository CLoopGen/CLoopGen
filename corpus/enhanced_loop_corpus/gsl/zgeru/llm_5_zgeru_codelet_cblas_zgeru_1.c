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
for (j = 0; j < N; ++j) {
    const double Y_real = (((const double *)Y)[2 * (jy)]);
    const double Y_imag = (((const double *)Y)[2 * (jy) + 1]);
    const double tmp_real = alpha_real * Y_real - alpha_imag * Y_imag;
    const double tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag;
    int ix_start, step;
    if (incX > 0) {
        ix_start = 0;
        step = incX;
    } else {
        ix_start = (M - 1) * (-incX);
        step = incX;
    }
    for (i = 0; i < M; ++i) {
        int offset_x = ix_start + i * step;
        const double X_real = (((const double *)X)[2 * offset_x]);
        const double X_imag = (((const double *)X)[2 * offset_x + 1]);
        int a_index = i + lda * j;
        (((double *)A)[2 * a_index]) += X_real * tmp_real - X_imag * tmp_imag;
        (((double *)A)[2 * a_index + 1]) += X_imag * tmp_real + X_real * tmp_imag;
    }
    jy += incY;
}
}
