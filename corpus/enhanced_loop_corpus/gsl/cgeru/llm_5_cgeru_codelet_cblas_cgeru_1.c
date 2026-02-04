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
    const float Y_imag = (((const float *)Y)[2 * (jy) + 1]);
    const float tmp_real = alpha_real * Y_real - alpha_imag * Y_imag;
    const float tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag;
    int ix_start, step;
    if (incX > 0) {
        ix_start = 0;
        step = incX;
    } else {
        ix_start = (M - 1) * (-incX);
        step = incX;
    }
    for (i = 0; i < M; i++) {
        int offset_x = 2 * (ix_start + i * step);
        const float X_real = (((const float *)X)[offset_x]);
        const float X_imag = (((const float *)X)[offset_x + 1]);
        int a_index = 2 * (i + lda * j);
        (((float *)A)[a_index]) += X_real * tmp_real - X_imag * tmp_imag;
        (((float *)A)[a_index + 1]) += X_imag * tmp_real + X_real * tmp_imag;
    }
    jy += incY;
}
}
