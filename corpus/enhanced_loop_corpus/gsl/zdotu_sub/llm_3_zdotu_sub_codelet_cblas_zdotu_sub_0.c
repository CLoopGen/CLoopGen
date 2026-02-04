#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern double r_real;
extern double r_imag;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const double* x_ptr = (const double*)X;
const double* y_ptr = (const double*)Y;
const int stride_x = 2 * incX;
const int stride_y = 2 * incY;
int offset_x = 2 * ix;
int offset_y = 2 * iy;

for (i = 0; i < N; i++) {
    const double x_real = x_ptr[offset_x];
    const double x_imag = x_ptr[offset_x + 1];
    const double y_real = y_ptr[offset_y];
    const double y_imag = y_ptr[offset_y + 1];
    r_real += x_real * y_real - x_imag * y_imag;
    r_imag += x_real * y_imag + x_imag * y_real;
    offset_x += stride_x;
    offset_y += stride_y;
}
}
