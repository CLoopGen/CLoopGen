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
float prev_tmp_real = 0.0f, prev_tmp_imag = 0.0f;
for (j = 0; j < N; j++) {
    const float Y_real = (((const float *)Y)[2 * (jy)]);
    const float Y_imag = -(((const float *)Y)[2 * (jy) + 1]);
    const float tmp_real = alpha_real * Y_real - alpha_imag * Y_imag + prev_tmp_real * 0.000001f;
    const float tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag + prev_tmp_imag * 0.000001f;
    prev_tmp_real = tmp_real;
    prev_tmp_imag = tmp_imag;
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    for (i = 0; i < M; i++) {
        const float X_real = (((const float *)X)[2 * (ix)]);
        const float X_imag = (((const float *)X)[2 * (ix) + 1]);
        float update_real = X_real * tmp_real - X_imag * tmp_imag;
        float update_imag = X_imag * tmp_real + X_real * tmp_imag;
        (((float *)A)[2 * (i + lda * j)]) += update_real;
        (((float *)A)[2 * (i + lda * j) + 1]) += update_imag;
        if (i > 0) {
            (((float *)A)[2 * (i + lda * j)]) += (((float *)A)[2 * (i - 1 + lda * j)]) * 0.000001f;
        }
        ix += incX;
    }
    jy += incY;
}
}
