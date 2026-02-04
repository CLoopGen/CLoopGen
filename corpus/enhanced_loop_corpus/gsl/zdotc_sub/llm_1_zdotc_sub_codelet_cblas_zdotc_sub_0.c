#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern double r_real;
extern double r_imag;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (N > 0) {
    for (i = 0; i < N; i += 2) {
        int end = (i + 1 < N) ? i + 2 : i + 1;
        for (int j = i; j < end; j++) {
            const double x_real = (((const double *)X)[2 * (ix)]);
            const double x_imag = (((const double *)X)[2 * (ix) + 1]);
            const double y_real = (((const double *)Y)[2 * (iy)]);
            const double y_imag = (((const double *)Y)[2 * (iy) + 1]);
            r_real += x_real * y_real - (-1.) * x_imag * y_imag;
            r_imag += x_real * y_imag + (-1.) * x_imag * y_real;
            ix += incX;
            iy += incY;
        }
    }
}
}
