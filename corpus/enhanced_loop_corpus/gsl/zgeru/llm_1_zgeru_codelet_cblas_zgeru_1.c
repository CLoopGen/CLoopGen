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
if (M <= 0 || N <= 0) return;
int iy = 0;
for (j = 0; j < N; j++) {
    for (i = 0; i < M; i++) {
        const double Y_real = (((const double *)Y)[2 * (iy)]);
        const double Y_imag = (((const double *)Y)[2 * (iy) + 1]);
        const double X_index = ((incX) > 0 ? i * incX : (M - 1 - i) * (-incX));
        const double X_real = (((const double *)X)[2 * ((int)X_index)]);
        const double X_imag = (((const double *)X)[2 * ((int)X_index) + 1]);
        const double tmp_real = alpha_real * Y_real - alpha_imag * Y_imag;
        const double tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag;
        (((double *)A)[2 * (i + lda * j)]) += X_real * tmp_real - X_imag * tmp_imag;
        (((double *)A)[2 * (i + lda * j) + 1]) += X_imag * tmp_real + X_real * tmp_imag;
    }
    iy += incY;
}
}
