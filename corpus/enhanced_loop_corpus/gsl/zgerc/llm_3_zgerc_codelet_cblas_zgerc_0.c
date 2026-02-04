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
    const int x_idx = 2 * ix;
    const double X_real = (((const double *)X)[x_idx]);
    const double X_imag = (((const double *)X)[x_idx + 1]);
    const double tmp_real = alpha_real * X_real - alpha_imag * X_imag;
    const double tmp_imag = alpha_imag * X_real + alpha_real * X_imag;
    for (j = 0; j < N; j++) {
        const int y_offset = 2 * ((incY > 0 ? j : (N - 1 - j)) * incY);
        const double Y_real = (((const double *)Y)[y_offset]);
        const double Y_imag = -(((const double *)Y)[y_offset + 1]);
        const int a_offset = 2 * (lda * i + j);
        (((double *)A)[a_offset]) += Y_real * tmp_real - Y_imag * tmp_imag;
        (((double *)A)[a_offset + 1]) += Y_imag * tmp_real + Y_real * tmp_imag;
    }
    ix += incX;
}
}
