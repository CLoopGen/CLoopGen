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
for (i = 0; i < N; i++) {
    const float x_real = (((const float *)X)[2 * (ix)]);
    const float x_imag = (((const float *)X)[2 * (ix) + 1]);
    const float y_real = (((const float *)Y)[2 * (iy)]);
    const float y_imag = (((const float *)Y)[2 * (iy) + 1]);
    if (x_real != 0.0f || x_imag != 0.0f) {
        r_real += x_real * y_real - (-1.) * x_imag * y_imag;
        r_imag += x_real * y_imag + (-1.) * x_imag * y_real;
    }
    ix += incX;
    iy += incY;
}
}
