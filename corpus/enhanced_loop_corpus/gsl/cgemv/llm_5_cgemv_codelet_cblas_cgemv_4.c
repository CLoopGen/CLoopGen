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
for (j = 0; j < lenX; j++) {
    float x_real = (((const float *)X)[2 * (ix)]);
    float x_imag = (((const float *)X)[2 * (ix) + 1]);
    float tmpR = alpha_real * x_real - alpha_imag * x_imag;
    float tmpI = alpha_real * x_imag + alpha_imag * x_real;
    int iy = 0;
    int incY_abs = incY > 0 ? incY : -incY;
    for (i = 0; i < lenY; i++) {
        const float A_real = (((const float *)A)[2 * (lda * j + i)]);
        const float A_imag = (((const float *)A)[2 * (lda * j + i) + 1]);
        int y_index = 2 * iy;
        float Y_real = (((float *)Y)[y_index]);
        float Y_imag = (((float *)Y)[y_index + 1]);
        Y_real += A_real * tmpR - (-A_imag) * tmpI;
        Y_imag += A_real * tmpI + (-A_imag) * tmpR;
        (((float *)Y)[y_index]) = Y_real;
        (((float *)Y)[y_index + 1]) = Y_imag;
        iy += incY_abs;
    }
    ix += incX;
}
}
