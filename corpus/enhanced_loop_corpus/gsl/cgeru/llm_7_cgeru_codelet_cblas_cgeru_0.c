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
float *A_cast = (float *)A;
const float *X_cast = (const float *)X;
const float *Y_cast = (const float *)Y;
int offset_x = 2 * ix;
for (i = 0; i < M; i++) {
    const float X_real = X_cast[offset_x];
    const float X_imag = X_cast[offset_x + 1];
    const float tmp_real = alpha_real * X_real - alpha_imag * X_imag;
    const float tmp_imag = alpha_imag * X_real + alpha_real * X_imag;
    int jy = ((incY) > 0 ? 0 : (N - 1) * (-incY));
    for (j = 0; j < N; j++) {
        int idx_y = 2 * jy;
        const float Y_real = Y_cast[idx_y];
        const float Y_imag = Y_cast[idx_y + 1];
        int idx_a = 2 * (lda * i + j);
        A_cast[idx_a]     = Y_real * tmp_real - Y_imag * tmp_imag;
        A_cast[idx_a + 1] = Y_imag * tmp_real + Y_real * tmp_imag;
        jy += incY;
    }
    offset_x += 2 * incX;
}
}
