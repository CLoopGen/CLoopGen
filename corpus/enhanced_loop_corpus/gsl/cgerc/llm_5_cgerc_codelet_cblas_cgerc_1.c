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
for (j = 0; j < N; j++) {
    const float Y_real = (((const float *)Y)[2 * (jy)]);
    const float Y_imag = -(((const float *)Y)[2 * (jy) + 1]);
    const float tmp_real = alpha_real * Y_real - alpha_imag * Y_imag;
    const float tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag;
    int ix_start = (incX > 0) ? 0 : (M - 1) * (-incX);
    for (i = 0; i < M; i++) {
        int offset_x = ix_start + i * incX;
        const float X_real = (((const float *)X)[2 * offset_x]);
        const float X_imag = (((const float *)X)[2 * offset_x + 1]);
        float *A_real_ptr = &(((float *)A)[2 * (i + lda * j)]);
        float *A_imag_ptr = A_real_ptr + 1;
        *A_real_ptr += X_real * tmp_real - X_imag * tmp_imag;
        *A_imag_ptr += X_imag * tmp_real + X_real * tmp_imag;
    }
    jy += incY;
}
}
