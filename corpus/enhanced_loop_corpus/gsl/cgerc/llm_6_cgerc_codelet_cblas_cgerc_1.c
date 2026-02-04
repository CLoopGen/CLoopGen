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
    int ix = ((incX) > 0 ? 0 : ((M) - 1) * (-(incX)));
    float temp_accum_real[8] __attribute__((aligned(32))) = {0};
    float temp_accum_imag[8] __attribute__((aligned(32))) = {0};
    for (i = 0; i < M; i += 8) {
        for (int k = 0; k < 8 && (i + k) < M; k++) {
            const float X_real = (((const float *)X)[2 * (ix + k * incX)]);
            const float X_imag = (((const float *)X)[2 * (ix + k * incX) + 1]);
            temp_accum_real[k] = X_real * tmp_real - X_imag * tmp_imag;
            temp_accum_imag[k] = X_imag * tmp_real + X_real * tmp_imag;
        }
        for (int k = 0; k < 8 && (i + k) < M; k++) {
            (((float *)A)[2 * (i + k + lda * j)]) += temp_accum_real[k];
            (((float *)A)[2 * (i + k + lda * j) + 1]) += temp_accum_imag[k];
        }
        ix += 8 * incX;
    }
    jy += incY;
}
}
