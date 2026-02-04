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
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed pointers and stride handling
    const double *x_ptr = (const double *)X;
    double *y_ptr = (double *)Y;
    const int x_stride = incX * 2;  // Since each complex number has 2 components
    const int y_stride = incY * 2;
    
    for (i = 0; i < N; i++) {
        const double x_real = x_ptr[ix];
        const double x_imag = x_ptr[ix + 1];
        y_ptr[iy] += (alpha_real * x_real - alpha_imag * x_imag);
        y_ptr[iy + 1] += (alpha_real * x_imag + alpha_imag * x_real);
        ix += x_stride;
        iy += y_stride;
    }
}
