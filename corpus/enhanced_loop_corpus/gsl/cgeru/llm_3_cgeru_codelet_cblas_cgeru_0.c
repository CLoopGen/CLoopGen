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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int x_stride = 2 * incX;
const int y_stride = 2 * incY;
int base_x_offset = 0;
for (i = 0; i < M; i++) {
    const float X_real = (((const float *)X)[base_x_offset]);
    const float X_imag = (((const float *)X)[base_x_offset + 1]);
    const float tmp_real = alpha_real * X_real - alpha_imag * X_imag;
    const float tmp_imag = alpha_imag * X_real + alpha_real * X_imag;
    int base_y_offset = 0;
    for (j = 0; j < N; j++) {
        const float Y_real = (((const float *)Y)[base_y_offset]);
        const float Y_imag = (((const float *)Y)[base_y_offset + 1]);
        const int a_index = 2 * (lda * i + j);
        (((float *)A)[a_index]) += Y_real * tmp_real - Y_imag * tmp_imag;
        (((float *)A)[a_index + 1]) += Y_imag * tmp_real + Y_real * tmp_imag;
        base_y_offset += y_stride;
    }
    base_x_offset += x_stride;
}
}
