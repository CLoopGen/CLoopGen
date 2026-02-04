#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *X;
extern  int incX;
extern int i;
extern int ix;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        const double x_real = (((double *)X)[2 * (ix)]);
        const double x_imag = (((double *)X)[2 * (ix) + 1]);
        if (x_real != 0.0 || x_imag != 0.0) {
            (((double *)X)[2 * (ix)]) = x_real * alpha_real - x_imag * alpha_imag;
            (((double *)X)[2 * (ix) + 1]) = x_real * alpha_imag + x_imag * alpha_real;
        }
        ix += incX;
    }
}
