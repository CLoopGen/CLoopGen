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
for (i = 0; i < N; i++) {
    const int x_idx = 2 * ix;
    const int y_idx = 2 * iy;
    const float tmp_real = ((float*)X)[x_idx];
    const float tmp_imag = ((float*)X)[x_idx + 1];
    ((float*)X)[x_idx] = ((float*)Y)[y_idx];
    ((float*)X)[x_idx + 1] = ((float*)Y)[y_idx + 1];
    ((float*)Y)[y_idx] = tmp_real;
    ((float*)Y)[y_idx + 1] = tmp_imag;
    ix += incX;
    iy += incY;
}
}
