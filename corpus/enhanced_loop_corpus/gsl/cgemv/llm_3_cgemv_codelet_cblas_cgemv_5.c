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
    int ix_start = ((incX) > 0 ? 0 : (lenX - 1) * (-incX));
    for (j = 0; j < lenX; j++) {
        int index_x = 2 * (ix_start + j * incX);
        int index_a = 2 * (lda * i + j);
        const float x_real = ((const float*)X)[index_x];
        const float x_imag = ((const float*)X)[index_x + 1];
        const float A_real = ((const float*)A)[index_a];
        const float A_imag = ((const float*)A)[index_a + 1];
        dotR += A_real * x_real + A_imag * x_imag;
        dotI += A_real * x_imag - A_imag * x_real;
    }
    int index_y = 2 * iy;
    ((float*)Y)[index_y]     += alpha_real * dotR - alpha_imag * dotI;
    ((float*)Y)[index_y + 1] += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
