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
    const int j_min = i - L;
    const int j_max = i + U + 1;
    int adjusted_j_min = j_min < 0 ? 0 : j_min;
    int adjusted_j_max = j_max > lenX ? lenX : j_max;
    int ix_start_offset = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    int ix = ix_start_offset + adjusted_j_min * incX;
    for (j = adjusted_j_min; j < adjusted_j_max; j++) {
        if (j >= lenX || j < 0) continue;
        const float x_real = (((const float *)X)[2 * (ix)]);
        const float x_imag = (((const float *)X)[2 * (ix) + 1]);
        int A_index = lda * i + (L + j - i);
        if (A_index < 0) {
            ix += incX;
            continue;
        }
        const float A_real = (((const float *)A)[2 * A_index]);
        const float A_imag = (((const float *)A)[2 * A_index + 1]);
        dotR += A_real * x_real + A_imag * x_imag;
        dotI += A_real * x_imag - A_imag * x_real;
        ix += incX;
    }
    float Y_real_temp = alpha_real * dotR - alpha_imag * dotI;
    float Y_imag_temp = alpha_real * dotI + alpha_imag * dotR;
    (((float *)Y)[2 * (iy)]) += Y_real_temp;
    (((float *)Y)[2 * (iy) + 1]) += Y_imag_temp;
    iy += incY;
}
}
