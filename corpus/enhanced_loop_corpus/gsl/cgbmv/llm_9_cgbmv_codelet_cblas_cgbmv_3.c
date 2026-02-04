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
for (j = 0; j < lenX && j < lenY; j++) {
    const float x_real = (((const float *)X)[2 * (ix)]);
    const float x_imag = (((const float *)X)[2 * (ix) + 1]);
    float tmpR = alpha_real * x_real;
    float tmpI = alpha_imag * x_real;
    float tmpR2 = alpha_real * x_imag;
    float tmpI2 = alpha_imag * x_imag;

    const float combined_real = tmpR - tmpI2;
    const float combined_imag = tmpR2 + tmpI;

    if (!(combined_real == 0. && combined_imag == 0.)) {
        const int bound = (lenY < (j + L + 1)) ? lenY : (j + L + 1);
        int base_offset_A = lda * j + U;
        int iy = ((incY) > 0 ? 0 : (lenY - 1) * (-incY)) + j * incY;

        for (i = j; i < bound; i++) {
            const float A_real = (((const float *)A)[2 * (base_offset_A + i - j)]);
            const float A_imag = (((const float *)A)[2 * (base_offset_A + i - j) + 1]);

            float y_real = (((float *)Y)[2 * iy]);
            float y_imag = (((float *)Y)[2 * iy + 1]);

            y_real += A_real * combined_real - A_imag * combined_imag;
            y_imag += A_real * combined_imag + A_imag * combined_real;

            (((float *)Y)[2 * iy]) = y_real;
            (((float *)Y)[2 * iy + 1]) = y_imag;

            iy += incY;
        }
    }
    ix += incX;
}
}
