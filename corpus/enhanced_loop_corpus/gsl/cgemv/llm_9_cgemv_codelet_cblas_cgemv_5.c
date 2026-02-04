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
extern  float alpha_real;
extern  float alpha_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i += 2) {
    float dotR0 = 0., dotR1 = 0.;
    float dotI0 = 0., dotI1 = 0.;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    for (j = 0; j < lenX; j++) {
        const float x_real = (((const float *)X)[2 * (ix)]);
        const float x_imag = (((const float *)X)[2 * (ix) + 1]);
        const float A_real0 = (((const float *)A)[2 * (lda * i + j)]);
        const float A_imag0 = (((const float *)A)[2 * (lda * i + j) + 1]);
        const float A_real1 = (((const float *)A)[2 * (lda * (i+1) + j)]);
        const float A_imag1 = (((const float *)A)[2 * (lda * (i+1) + j) + 1]);
        dotR0 += A_real0 * x_real + A_imag0 * x_imag;
        dotI0 += A_real0 * x_imag - A_imag0 * x_real;
        dotR1 += A_real1 * x_real + A_imag1 * x_imag;
        dotI1 += A_real1 * x_imag - A_imag1 * x_real;
        ix += incX;
    }
    (((float *)Y)[2 * (iy)]) += alpha_real * dotR0 - alpha_imag * dotI0;
    (((float *)Y)[2 * (iy) + 1]) += alpha_real * dotI0 + alpha_imag * dotR0;
    if (i + 1 < lenY) {
        (((float *)Y)[2 * (iy + incY)]) += alpha_real * dotR1 - alpha_imag * dotI1;
        (((float *)Y)[2 * (iy + incY) + 1]) += alpha_real * dotI1 + alpha_imag * dotR1;
    }
    iy += 2 * incY;
}
}
