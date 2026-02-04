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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < M; i++) {
    const float X_real = (((const float *)X)[2 * (ix)]);
    const float X_imag = (((const float *)X)[2 * (ix) + 1]);
    const float tmp_real = alpha_real * X_real - alpha_imag * X_imag;
    const float tmp_imag = alpha_imag * X_real + alpha_real * X_imag;
    int jy = (incY >= 0) ? 0 : (N - 1) * (-incY);
    for (j = 0; j < N; j++) {
        if (jy >= 0) {
            const float Y_real = (((const float *)Y)[2 * jy]);
            const float Y_imag = (((const float *)Y)[2 * jy + 1]);
            float *A_real_ptr = &(((float *)A)[2 * (lda * i + j)]);
            float *A_imag_ptr = A_real_ptr + 1;
            *A_real_ptr += Y_real * tmp_real - Y_imag * tmp_imag;
            *A_imag_ptr += Y_imag * tmp_real + Y_real * tmp_imag;
        }
        jy += incY;
    }
    ix += incX;
}
}
