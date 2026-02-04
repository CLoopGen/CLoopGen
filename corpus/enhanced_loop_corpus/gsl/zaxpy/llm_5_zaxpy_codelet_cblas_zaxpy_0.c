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
    for (i = 0; i < N; i++) {
        const double x_real = (((const double *)X)[2 * (ix)]);
        const double x_imag = (((const double *)X)[2 * (ix) + 1]);
        if (alpha_real != 0.0 || alpha_imag != 0.0) {
            (((double *)Y)[2 * (iy)]) += (alpha_real * x_real - alpha_imag * x_imag);
            (((double *)Y)[2 * (iy) + 1]) += (alpha_real * x_imag + alpha_imag * x_real);
        }
        ix += incX;
        iy += incY;
    }
}
