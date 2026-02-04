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
extern  float alpha_real;
extern  float alpha_imag;
extern int jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (M <= 0 || N <= 0) return;
int iy = 0;
for (j = 0; j < N; j++) {
    const float Y_real = (((const float *)Y)[2 * iy]);
    const float Y_imag = -(((const float *)Y)[2 * iy + 1]);
    const float tmp_real = alpha_real * Y_real - alpha_imag * Y_imag;
    const float tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag;
    int ix = ((incX) > 0 ? 0 : (M - 1) * (-incX));
    for (i = 0; i < M; i++) {
        const float X_real = (((const float *)X)[2 * ix]);
        const float X_imag = (((const float *)X)[2 * ix + 1]);
        int A_index = 2 * (i + lda * j);
        ((float*)A)[A_index] += X_real * tmp_real - X_imag * tmp_imag;
        ((float*)A)[A_index + 1] += X_imag * tmp_real + X_real * tmp_imag;
        ix += incX;
    }
    iy += incY;
}
}
