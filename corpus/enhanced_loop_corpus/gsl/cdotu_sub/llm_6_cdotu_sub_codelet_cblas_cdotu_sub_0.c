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
    float temp_r_real = r_real;
    float temp_r_imag = r_imag;
    int local_ix = ix;
    int local_iy = iy;
    for (i = 0; i < N; i++) {
        const float x_real = (((const float *)X)[2 * local_ix]);
        const float x_imag = (((const float *)X)[2 * local_ix + 1]);
        const float y_real = (((const float *)Y)[2 * local_iy]);
        const float y_imag = (((const float *)Y)[2 * local_iy + 1]);
        temp_r_real += x_real * y_real - 1. * x_imag * y_imag;
        temp_r_imag += x_real * y_imag + 1. * x_imag * y_real;
        local_ix += incX;
        local_iy += incY;
    }
    r_real = temp_r_real;
    r_imag = temp_r_imag;
}
