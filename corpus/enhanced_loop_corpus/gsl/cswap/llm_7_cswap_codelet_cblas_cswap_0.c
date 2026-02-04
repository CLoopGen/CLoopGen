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
    int prev_ix = ix - incX;
    int prev_iy = iy - incY;
    for (i = 0; i < N; i++) {
        const float tmp_real = x_float[2 * (ix)];
        const float tmp_imag = x_float[2 * (ix) + 1];
        x_float[2 * (ix)] = y_float[2 * (iy)];
        x_float[2 * (ix) + 1] = y_float[2 * (iy) + 1];
        if (i > 0) {
            y_float[2 * prev_iy] = tmp_real;
            y_float[2 * prev_iy + 1] = tmp_imag;
        }
        prev_ix = ix;
        prev_iy = iy;
        ix += incX;
        iy += incY;
    }
    if (N > 0) {
        const float final_tmp_real = ((float*)X)[2 * (ix - incX)];
        const float final_tmp_imag = ((float*)X)[2 * (ix - incX) + 1];
        ((float*)Y)[2 * (iy - incY)] = final_tmp_real;
        ((float*)Y)[2 * (iy - incY) + 1] = final_tmp_imag;
    }
}
