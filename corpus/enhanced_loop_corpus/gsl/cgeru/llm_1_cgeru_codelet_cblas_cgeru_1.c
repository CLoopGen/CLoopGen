#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int M;
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern void *A;
extern  int lda;
extern int i;
extern int j;
extern  float alpha_real;
extern  float alpha_imag;
extern int jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (M <= 0 || N <= 0) return;
const int total_elements = M * N;
for (int idx = 0; idx < total_elements; idx++) {
    const int j = idx / M;
    const int i = idx % M;
    const float Y_real = (((const float *)Y)[2 * (jy + j * incY)]);
    const float Y_imag = (((const float *)Y)[2 * (jy + j * incY) + 1]);
    const float tmp_real = alpha_real * Y_real - alpha_imag * Y_imag;
    const float tmp_imag = alpha_imag * Y_real + alpha_real * Y_imag;
    const int ix_offset = ((incX) > 0 ? i * incX : (M - 1 - i) * (-incX));
    const float X_real = (((const float *)X)[2 * ix_offset]);
    const float X_imag = (((const float *)X)[2 * ix_offset + 1]);
    (((float *)A)[2 * (i + lda * j)]) += X_real * tmp_real - X_imag * tmp_imag;
    (((float *)A)[2 * (i + lda * j) + 1]) += X_imag * tmp_real + X_real * tmp_imag;
}
}

