#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *x_float = (float *)X;
    float *y_float = (float *)Y;
    int local_ix = 0;
    int local_iy = 0;
    for (i = 0; i < N; i++) {
        const float tmp_real = x_float[2 * local_ix];
        const float tmp_imag = x_float[2 * local_ix + 1];
        x_float[2 * local_ix] = y_float[2 * local_iy];
        x_float[2 * local_ix + 1] = y_float[2 * local_iy + 1];
        y_float[2 * local_iy] = tmp_real;
        y_float[2 * local_iy + 1] = tmp_imag;
        local_ix += incX;
        local_iy += incY;
    }
}
