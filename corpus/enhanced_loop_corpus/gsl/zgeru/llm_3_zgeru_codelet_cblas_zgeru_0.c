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
const double* X_ptr = (const double*)X;
const double* Y_ptr = (const double*)Y;
double* A_ptr = (double*)A;
for (i = 0; i < M; i++) {
    int x_offset = 2 * ix;
    const double X_real = X_ptr[x_offset];
    const double X_imag = X_ptr[x_offset + 1];
    const double tmp_real = alpha_real * X_real - alpha_imag * X_imag;
    const double tmp_imag = alpha_imag * X_real + alpha_real * X_imag;
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j < N; j++) {
        int y_offset = 2 * jy;
        const double Y_real = Y_ptr[y_offset];
        const double Y_imag = Y_ptr[y_offset + 1];
        int a_offset = 2 * (lda * i + j);
        A_ptr[a_offset] += Y_real * tmp_real - Y_imag * tmp_imag;
        A_ptr[a_offset + 1] += Y_imag * tmp_real + Y_real * tmp_imag;
        jy += incY;
    }
    ix += incX;
}
}
