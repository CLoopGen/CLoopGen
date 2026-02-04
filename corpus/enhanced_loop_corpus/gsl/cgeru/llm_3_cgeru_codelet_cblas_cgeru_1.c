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
const float *Y_arr = (const float *)Y;
const float *X_arr = (const float *)X;
float *A_arr = (float *)A;
for (j = 0; j < N; j++) {
    const int y_index = 2 * jy;
    const float Y_real = Y_arr[y_index];
    const float Y_imag = Y_arr[y_index + 1];
    const float tmp_real = alpha_real * Y_real - alpha_imag * Y_imag;
    const float tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag;
    int ix = ((incX) > 0 ? 0 : (M - 1) * (-incX));
    for (i = 0; i < M; i++) {
        const int x_index = 2 * ix;
        const float X_real = X_arr[x_index];
        const float X_imag = X_arr[x_index + 1];
        const int a_offset = 2 * i + 2 * lda * j;
        A_arr[a_offset]     += X_real * tmp_real - X_imag * tmp_imag;
        A_arr[a_offset + 1] += X_imag * tmp_real + X_real * tmp_imag;
        ix += incX;
    }
    jy += incY;
}
}
