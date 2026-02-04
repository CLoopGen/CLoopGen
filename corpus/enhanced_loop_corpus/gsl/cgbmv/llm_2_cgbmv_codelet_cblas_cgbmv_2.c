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
    int ix_base = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    int offset_A = 2 * (lda * i + L - i);
    for (j = j_min; j < j_max; j++) {
        int offset_X = 2 * (ix_base + j * incX);
        int offset_A_j = offset_A + 2 * j;
        const float x_real = ((const float *)X)[offset_X];
        const float x_imag = ((const float *)X)[offset_X + 1];
        const float A_real = ((const float *)A)[offset_A_j];
        const float A_imag = ((const float *)A)[offset_A_j + 1];
        dotR += A_real * x_real - A_imag * x_imag;
        dotI += A_real * x_imag + A_imag * x_real;
    }
    int offset_Y = 2 * iy;
    ((float *)Y)[offset_Y] += alpha_real * dotR - alpha_imag * dotI;
    ((float *)Y)[offset_Y + 1] += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
