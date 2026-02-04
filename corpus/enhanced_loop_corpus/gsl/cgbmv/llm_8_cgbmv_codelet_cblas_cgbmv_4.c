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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < lenX; j += 2) {
    const float x_real1 = (((const float *)X)[2 * (ix)]);
    const float x_imag1 = (((const float *)X)[2 * (ix) + 1]);
    float tmpR1 = alpha_real * x_real1 - alpha_imag * x_imag1;
    float tmpI1 = alpha_real * x_imag1 + alpha_imag * x_real1;

    const float x_real2 = (((const float *)X)[2 * (ix + incX)]);
    const float x_imag2 = (((const float *)X)[2 * (ix + incX) + 1]);
    float tmpR2 = alpha_real * x_real2 - alpha_imag * x_imag2;
    float tmpI2 = alpha_real * x_imag2 + alpha_imag * x_real2;

    if (!(tmpR1 == 0. && tmpI1 == 0.)) {
        const int i_min = (j > U ? j - U : 0);
        const int i_max = ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1));
        int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i_min * incY;
        for (i = i_min; i < i_max; i++) {
            const float A_real = (((const float *)A)[2 * (lda * j + (U + i - j))]);
            const float A_imag = (((const float *)A)[2 * (lda * j + (U + i - j)) + 1]);
            (((float *)Y)[2 * (iy)]) += A_real * tmpR1 - (-A_imag) * tmpI1;
            (((float *)Y)[2 * (iy) + 1]) += A_real * tmpI1 + (-A_imag) * tmpR1;
            iy += incY;
        }
    }

    if (j + 1 < lenX && !(tmpR2 == 0. && tmpI2 == 0.)) {
        const int i_min = (j + 1 > U ? j + 1 - U : 0);
        const int i_max = ((lenY) < (j + 1 + L + 1) ? (lenY) : (j + 1 + L + 1));
        int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i_min * incY;
        for (i = i_min; i < i_max; i++) {
            const float A_real = (((const float *)A)[2 * (lda * (j + 1) + (U + i - (j + 1)))]);
            const float A_imag = (((const float *)A)[2 * (lda * (j + 1) + (U + i - (j + 1))) + 1]);
            (((float *)Y)[2 * (iy)]) += A_real * tmpR2 - (-A_imag) * tmpI2;
            (((float *)Y)[2 * (iy) + 1]) += A_real * tmpI2 + (-A_imag) * tmpR2;
            iy += incY;
        }
    }
    ix += 2 * incX;
}
}
