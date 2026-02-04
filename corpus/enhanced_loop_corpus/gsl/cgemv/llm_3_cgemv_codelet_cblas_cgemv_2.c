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
for (i = 0; i < lenY; i++) {
    float dotR = 0.;
    float dotI = 0.;
    const int base_A = 2 * lda * i;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    for (j = 0; j < lenX; j++) {
        const int offset_X = 2 * ix;
        const int offset_A = base_A + 2 * j;
        const float x_real = ((const float*)X)[offset_X];
        const float x_imag = ((const float*)X)[offset_X + 1];
        const float A_real = ((const float*)A)[offset_A];
        const float A_imag = ((const float*)A)[offset_A + 1];
        dotR += A_real * x_real - A_imag * x_imag;
        dotI += A_real * x_imag + A_imag * x_real;
        ix += incX;
    }
    const int offset_Y = 2 * iy;
    ((float*)Y)[offset_Y]     += alpha_real * dotR - alpha_imag * dotI;
    ((float*)Y)[offset_Y + 1] += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
