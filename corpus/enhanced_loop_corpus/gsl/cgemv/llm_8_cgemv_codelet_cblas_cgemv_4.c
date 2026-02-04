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
for (j = 0; j < lenX; j += 2) {
    float x_real1, x_imag1, x_real2, x_imag2;
    float tmpR1, tmpI1, tmpR2, tmpI2;

    ix = j * incX;
    x_real1 = (((const float *)X)[2 * (ix)]);
    x_imag1 = (((const float *)X)[2 * (ix) + 1]);
    tmpR1 = alpha_real * x_real1 - alpha_imag * x_imag1;
    tmpI1 = alpha_real * x_imag1 + alpha_imag * x_real1;

    if (j + 1 < lenX) {
        x_real2 = (((const float *)X)[2 * (ix + incX)]);
        x_imag2 = (((const float *)X)[2 * (ix + incX) + 1]);
        tmpR2 = alpha_real * x_real2 - alpha_imag * x_imag2;
        tmpI2 = alpha_real * x_imag2 + alpha_imag * x_real2;
    }

    int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
    for (i = 0; i < lenY; i++) {
        const float A_real1 = (((const float *)A)[2 * (lda * j + i)]);
        const float A_imag1 = (((const float *)A)[2 * (lda * j + i) + 1]);
        (((float *)Y)[2 * (iy)]) += A_real1 * tmpR1 - (-A_imag1) * tmpI1;
        (((float *)Y)[2 * (iy) + 1]) += A_real1 * tmpI1 + (-A_imag1) * tmpR1;

        if (j + 1 < lenX) {
            const float A_real2 = (((const float *)A)[2 * (lda * (j + 1) + i)]);
            const float A_imag2 = (((const float *)A)[2 * (lda * (j + 1) + i) + 1]);
            int iy2 = iy + incY * (i == 0 ? 0 : 0); // Use same iy offset logic
            (((float *)Y)[2 * (iy) + 2 * incY]) += A_real2 * tmpR2 - (-A_imag2) * tmpI2;
            (((float *)Y)[2 * (iy) + 2 * incY + 1]) += A_real2 * tmpI2 + (-A_imag2) * tmpR2;
        }
        iy += incY;
    }
}
}
