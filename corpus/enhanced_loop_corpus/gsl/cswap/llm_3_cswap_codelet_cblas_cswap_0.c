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
const float* x_base = (const float*)X;
float* x_ptr = (float*)X;
float* y_ptr = (float*)Y;
for (i = 0; i < N; i++) {
    const int x_offset = 2 * ix;
    const int y_offset = 2 * iy;
    const float tmp_real = x_ptr[x_offset];
    const float tmp_imag = x_ptr[x_offset + 1];
    x_ptr[x_offset] = y_ptr[y_offset];
    x_ptr[x_offset + 1] = y_ptr[y_offset + 1];
    y_ptr[y_offset] = tmp_real;
    y_ptr[y_offset + 1] = tmp_imag;
    ix += incX;
    iy += incY;
}
}
