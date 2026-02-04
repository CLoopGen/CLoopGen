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
float *y_ptr = (float *)Y;
for (i = 0; i < lenY; i++) {
    float dotR = 0.;
    float dotI = 0.;
    int ix_start = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX)));
    for (j = 0; j < lenX; j++) {
        int offset_X = 2 * (ix_start + j * incX);
        int offset_A = 2 * (lda * i + j);
        const float x_real = ((const float *)X)[offset_X];
        const float x_imag = ((const float *)X)[offset_X + 1];
        const float A_real = ((const float *)A)[offset_A];
        const float A_imag = ((const float *)A)[offset_A + 1];
        dotR += A_real * x_real + A_imag * x_imag;
        dotI += A_real * x_imag - A_imag * x_real;
    }
    int iy_offset = 2 * (iy);
    float Y_temp_real = y_ptr[iy_offset];
    float Y_temp_imag = y_ptr[iy_offset + 1];
    Y_temp_real += alpha_real * dotR - alpha_imag * dotI;
    Y_temp_imag += alpha_real * dotI + alpha_imag * dotR;
    y_ptr[iy_offset] = Y_temp_real;
    y_ptr[iy_offset + 1] = Y_temp_imag;
    iy += incY;
}
}
