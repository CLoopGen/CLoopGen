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
const double* x_arr = (const double*)X;
const double* y_arr = (const double*)Y;
int offset_x = 0;
int offset_y = 0;
for (i = 0; i < N; i++) {
    const double x_real = x_arr[offset_x];
    const double x_imag = x_arr[offset_x + 1];
    const double y_real = y_arr[offset_y];
    const double y_imag = y_arr[offset_y + 1];
    r_real += x_real * y_real - (-1.) * x_imag * y_imag;
    r_imag += x_real * y_imag + (-1.) * x_imag * y_real;
    offset_x += 2 * incX;
    offset_y += 2 * incY;
}
}
