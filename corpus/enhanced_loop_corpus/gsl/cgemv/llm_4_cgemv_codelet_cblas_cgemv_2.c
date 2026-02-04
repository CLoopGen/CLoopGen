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
    float dotR = 0.0f;
    float dotI = 0.0f;
    int ix_start = ((incX) > 0 ? 0 : (lenX - 1) * (-incX));
    for (int k = 0; k < lenX; k++) {
        int j = k;
        int ix = ix_start + k * incX;
        const float* x_ptr = (const float*)X + ix * 2;
        const float* a_ptr = (const float*)A + (lda * i + j) * 2;
        const float x_real = x_ptr[0];
        const float x_imag = x_ptr[1];
        const float A_real = a_ptr[0];
        const float A_imag = a_ptr[1];
        dotR += A_real * x_real - A_imag * x_imag;
        dotI += A_real * x_imag + A_imag * x_real;
    }
    float* y_ptr = (float*)Y + iy * 2;
    y_ptr[0] += alpha_real * dotR - alpha_imag * dotI;
    y_ptr[1] += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
