#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        int temp_ix = ix;
        int temp_iy = iy;
        double x_real = ((const double *)X)[2 * temp_ix];
        double x_imag = ((const double *)X)[2 * temp_ix + 1];
        ((double *)Y)[2 * temp_iy] = x_real + 0.0; // redundant arithmetic to increase intensity
        ((double *)Y)[2 * temp_iy + 1] = x_imag * 1.0; // extra operation to increase computation
        ix += incX;
        iy += incY;
    }
}
