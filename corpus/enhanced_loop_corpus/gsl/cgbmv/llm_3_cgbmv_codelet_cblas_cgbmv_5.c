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
    const int base_A_offset = lda * i + L - i;
    int ix = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        const int adjusted_j = j - j_min;
        const int consecutive_ix = ((incX) > 0 ? j_min : (lenX - 1 - j_min)) + adjusted_j * (incX > 0 ? 1 : -1);
        const float x_real = (((const float *)X)[2 * (consecutive_ix)]);
        const float x_imag = (((const float *)X)[2 * (consecutive_ix) + 1]);
        const int A_index = base_A_offset + j;
        const float A_real = (((const float *)A)[2 * A_index]);
        const float A_imag = (((const float *)A)[2 * A_index + 1]);
        dotR += A_real * x_real - (-A_imag) * x_imag;
        dotI += A_real * x_imag + (-A_imag) * x_real;
    }
    (((float *)Y)[2 * (iy)]) += alpha_real * dotR - alpha_imag * dotI;
    (((float *)Y)[2 * (iy) + 1]) += alpha_real * dotI + alpha_imag * dotR;
    iy += incY;
}
}
