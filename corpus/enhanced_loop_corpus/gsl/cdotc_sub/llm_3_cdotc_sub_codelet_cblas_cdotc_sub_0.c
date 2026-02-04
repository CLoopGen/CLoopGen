#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern float r_real;
extern float r_imag;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const float* x_arr = (const float*)X;
const float* y_arr = (const float*)Y;
for (i = 0; i < N; i++) {
    const int offset_x = 2 * ix;
    const int offset_y = 2 * iy;
    const float x_real = x_arr[offset_x];
    const float x_imag = x_arr[offset_x + 1];
    const float y_real = y_arr[offset_y];
    const float y_imag = y_arr[offset_y + 1];
    r_real += x_real * y_real - (-1.) * x_imag * y_imag;
    r_imag += x_real * y_imag + (-1.) * x_imag * y_real;
    ix += incX;
    iy += incY;
}
}
