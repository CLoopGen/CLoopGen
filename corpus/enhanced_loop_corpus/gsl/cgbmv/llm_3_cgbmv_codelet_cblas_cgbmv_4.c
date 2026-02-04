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
for (j = 0; j < lenX; j++) {
    const int x_offset = 2 * ix;
    const float x_real = (((const float *)X)[x_offset]);
    const float x_imag = (((const float *)X)[x_offset + 1]);
    float tmpR = alpha_real * x_real - alpha_imag * x_imag;
    float tmpI = alpha_real * x_imag + alpha_imag * x_real;
    if (!(tmpR == 0. && tmpI == 0.)) {
        const int i_min = (j > U ? j - U : 0);
        const int i_max = ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1));
        const int base_iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
        for (i = i_min; i < i_max; i++) {
            const int a_offset = 2 * (lda * j + (U + i - j));
            const float A_real = (((const float *)A)[a_offset]);
            const float A_imag = (((const float *)A)[a_offset + 1]);
            const int y_offset = 2 * (base_iy + (i - i_min) * incY + i_min * incY);
            (((float *)Y)[y_offset]) += A_real * tmpR - (-A_imag) * tmpI;
            (((float *)Y)[y_offset + 1]) += A_real * tmpI + (-A_imag) * tmpR;
        }
    }
    ix += incX;
}
}
