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
    int jy = ((incY) > 0 ? 0 : ((N) - 1) * (-(incY)));
    for (j = 0; j < N; j += 2) {
        if (j + 1 < N) {
            const float Y_real0 = (((const float *)Y)[2 * (jy)]);
            const float Y_imag0 = (((const float *)Y)[2 * (jy) + 1]);
            const float Y_real1 = (((const float *)Y)[2 * (jy + incY)]);
            const float Y_imag1 = (((const float *)Y)[2 * (jy + incY) + 1]);

            float *A0 = &(((float *)A)[2 * (lda * i + j)]);
            float *A1 = &(((float *)A)[2 * (lda * i + j + 1)]);

            A0[0] += Y_real0 * tmp_real - Y_imag0 * tmp_imag;
            A0[1] += Y_imag0 * tmp_real + Y_real0 * tmp_imag;

            A1[0] += Y_real1 * tmp_real - Y_imag1 * tmp_imag;
            A1[1] += Y_imag1 * tmp_real + Y_real1 * tmp_imag;
        } else {
            const float Y_real = (((const float *)Y)[2 * (jy)]);
            const float Y_imag = (((const float *)Y)[2 * (jy) + 1]);
            (((float *)A)[2 * (lda * i + j)]) += Y_real * tmp_real - Y_imag * tmp_imag;
            (((float *)A)[2 * (lda * i + j) + 1]) += Y_imag * tmp_real + Y_real * tmp_imag;
        }
        jy += 2 * incY;
    }
    ix += incX;
}
}
