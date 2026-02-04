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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float temp_accum[2] = {0.0f, 0.0f};
for (j = 0; j < lenX; j++) {
    float x_real = (((const float *)X)[2 * (ix)]);
    float x_imag = (((const float *)X)[2 * (ix) + 1]);
    float tmpR = alpha_real * x_real - alpha_imag * x_imag;
    float tmpI = alpha_real * x_imag + alpha_imag * x_real;
    int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
    for (i = 0; i < lenY; i++) {
        const float A_real = (((const float *)A)[2 * (lda * j + i)]);
        const float A_imag = (((const float *)A)[2 * (lda * j + i) + 1]);
        temp_accum[0] = A_real * tmpR - A_imag * tmpI;
        temp_accum[1] = A_real * tmpI + A_imag * tmpR;
        (((float *)Y)[2 * (iy)]) += temp_accum[0];
        (((float *)Y)[2 * (iy) + 1]) += temp_accum[1];
        iy += incY;
    }
    ix += incX;
}
}
