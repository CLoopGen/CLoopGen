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
    int ix = 0;
    if (incX >= 0) {
        for (i = 0; i < M; i++) {
            const float X_real = (((const float *)X)[2 * (ix)]);
            const float X_imag = (((const float *)X)[2 * (ix) + 1]);
            (((float *)A)[2 * (i + lda * j)]) += X_real * tmp_real - X_imag * tmp_imag;
            (((float *)A)[2 * (i + lda * j) + 1]) += X_imag * tmp_real + X_real * tmp_imag;
            ix += incX;
        }
    } else {
        ix = (M - 1) * (-incX);
        for (i = 0; i < M; i++) {
            const float X_real = (((const float *)X)[2 * (ix)]);
            const float X_imag = (((const float *)X)[2 * (ix) + 1]);
            (((float *)A)[2 * (i + lda * j)]) += X_real * tmp_real - X_imag * tmp_imag;
            (((float *)A)[2 * (i + lda * j) + 1]) += X_imag * tmp_real + X_real * tmp_imag;
            ix += incX;
        }
    }
    jy += incY;
}
}
