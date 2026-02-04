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
const double * restrict x_base = (const double *)X;
double * restrict x_mod = (double *)X;
const double * restrict y_base = (const double *)Y;
double * restrict y_mod = (double *)Y;
for (i = 0; i < N; i++) {
    const int x_offset = 2 * ix;
    const int y_offset = 2 * iy;
    const double tmp_real = x_mod[x_offset];
    const double tmp_imag = x_mod[x_offset + 1];
    x_mod[x_offset] = y_mod[y_offset];
    x_mod[x_offset + 1] = y_mod[y_offset + 1];
    y_mod[y_offset] = tmp_real;
    y_mod[y_offset + 1] = tmp_imag;
    ix += incX;
    iy += incY;
}
}
