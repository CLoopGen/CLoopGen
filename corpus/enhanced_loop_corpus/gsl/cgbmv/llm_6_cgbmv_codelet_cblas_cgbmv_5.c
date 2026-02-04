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
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        const float x_real = (((const float *)X)[2 * (ix)]);
        const float x_imag = (((const float *)X)[2 * (ix) + 1]);
        const float A_real = (((const float *)A)[2 * (lda * i + (L + j - i))]);
        const float A_imag = (((const float *)A)[2 * (lda * i + (L + j - i)) + 1]);
        float temp_real = A_real * x_real - (-A_imag) * x_imag;
        float temp_imag = A_real * x_imag + (-A_imag) * x_real;
        dotR = dotR + temp_real;
        dotI = dotI + temp_imag;
        ix += incX;
    }
    float yr = (((float *)Y)[2 * (iy)]);
    float yi = (((float *)Y)[2 * (iy) + 1]);
    yr += alpha_real * dotR - alpha_imag * dotI;
    yi += alpha_real * dotI + alpha_imag * dotR;
    (((float *)Y)[2 * (iy)]) = yr;
    (((float *)Y)[2 * (iy) + 1]) = yi;
    iy += incY;
}
}
