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
    const ptrdiff_t x_idx = 2 * ix;
    const ptrdiff_t y_idx = 2 * iy;
    const double tmp_real = ((double *)X)[x_idx];
    const double tmp_imag = ((double *)X)[x_idx + 1];
    ((double *)X)[x_idx] = ((double *)Y)[y_idx];
    ((double *)X)[x_idx + 1] = ((double *)Y)[y_idx + 1];
    ((double *)Y)[y_idx] = tmp_real;
    ((double *)Y)[y_idx + 1] = tmp_imag;
    ix += incX;
    iy += incY;
}
}
