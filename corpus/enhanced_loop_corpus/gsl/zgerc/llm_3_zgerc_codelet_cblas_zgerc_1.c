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
for (j = 0; j < N; j++) {
    const ptrdiff_t y_offset = 2 * jy;
    const double Y_real = (((const double *)Y)[y_offset]);
    const double Y_imag = -(((const double *)Y)[y_offset + 1]);
    const double tmp_real = alpha_real * Y_real - alpha_imag * Y_imag;
    const double tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag;
    for (i = 0; i < M; i++) {
        const int x_index = (incX > 0 ? i * incX : (M - 1 - i) * (-incX));
        const ptrdiff_t x_offset = 2 * x_index;
        const double X_real = (((const double *)X)[x_offset]);
        const double X_imag = (((const double *)X)[x_offset + 1]);
        const ptrdiff_t a_offset = 2 * (i + lda * j);
        (((double *)A)[a_offset]) += X_real * tmp_real - X_imag * tmp_imag;
        (((double *)A)[a_offset + 1]) += X_imag * tmp_real + X_real * tmp_imag;
    }
    jy += incY;
}
}
