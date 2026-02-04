#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  void *A;
extern  int lda;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern int L;
extern int U;
extern  float alpha_real;
extern  float alpha_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i++) {
    float dotR = 0.;
    float dotI = 0.;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    const float* X_ptr = (const float*)X;
    const float* A_ptr = (const float*)A;
    float* Y_ptr = (float*)Y;
    int base_ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    int idx_A_start = lda * i + (L - i);
    for (j = j_min; j < j_max; j++) {
        int idx_X = base_ix + (j - j_min) * incX;
        int idx_A = idx_A_start + j;
        const float x_real = X_ptr[2 * idx_X];
        const float x_imag = X_ptr[2 * idx_X + 1];
        const float A_real = A_ptr[2 * idx_A];
        const float A_imag = A_ptr[2 * idx_A + 1];
        dotR += A_real * x_real - A_imag * x_imag;
        dotI += A_real * x_imag + A_imag * x_real;
    }
    int idx_Y = iy;
    Y_ptr[2 * idx_Y] += alpha_real * dotR - alpha_imag * dotI;
    Y_ptr[2 * idx_Y + 1] += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
