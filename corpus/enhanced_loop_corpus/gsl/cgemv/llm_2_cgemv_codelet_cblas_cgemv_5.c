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
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    const float* x_base = (const float*)X;
    const float* A_row = (const float*)A + 2 * (lda * i);
    for (j = 0; j < lenX; j++) {
        const float x_real = x_base[2 * ix];
        const float x_imag = x_base[2 * ix + 1];
        const float A_real = A_row[2 * j];
        const float A_imag = A_row[2 * j + 1];
        dotR += A_real * x_real - (-A_imag) * x_imag;
        dotI += A_real * x_imag + (-A_imag) * x_real;
        ix += incX;
    }
    float* y_ptr = (float*)Y + 2 * iy;
    y_ptr[0] += alpha_real * dotR - alpha_imag * dotI;
    y_ptr[1] += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
