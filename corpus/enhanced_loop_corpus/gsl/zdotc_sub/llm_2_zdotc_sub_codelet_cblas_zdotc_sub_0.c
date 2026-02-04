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
for (i = 0; i < N; i++) {
    const int index_x_real = 2 * ix;
    const int index_y_real = 2 * iy;
    const double x_real = ((const double*)X)[index_x_real];
    const double x_imag = ((const double*)X)[index_x_real + 1];
    const double y_real = ((const double*)Y)[index_y_real];
    const double y_imag = ((const double*)Y)[index_y_real + 1];
    r_real += x_real * y_real - (-1.) * x_imag * y_imag;
    r_imag += x_real * y_imag + (-1.) * x_imag * y_real;
    ix += incX;
    iy += incY;
}
}
