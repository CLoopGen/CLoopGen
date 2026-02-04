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
if (lenY > 0 && lenX > 0) {
    float dotR, dotI;
    int ix, current_iy = iy;
    for (i = 0; i < lenY; i++) {
        dotR = 0.;
        dotI = 0.;
        ix = ((incX) > 0 ? 0 : (lenX - 1) * (-incX));
        for (j = 0; j < lenX; j++) {
            const float x_real = ((const float*)X)[2 * ix];
            const float x_imag = ((const float*)X)[2 * ix + 1];
            const float A_real = ((const float*)A)[2 * (lda * i + j)];
            const float A_imag = ((const float*)A)[2 * (lda * i + j) + 1];
            dotR += A_real * x_real - A_imag * x_imag;
            dotI += A_real * x_imag + A_imag * x_real;
            ix += incX;
        }
        ((float*)Y)[2 * current_iy] += alpha_real * dotR - alpha_imag * dotI;
        ((float*)Y)[2 * current_iy + 1] += alpha_real * dotI + alpha_imag * dotR;
        current_iy += incY;
    }
    iy = current_iy;
}
}
