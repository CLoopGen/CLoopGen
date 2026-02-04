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
for (i = 0; i < N; i += 2) {
    const double x_real1 = (((const double *)X)[2 * (ix)]);
    const double x_imag1 = (((const double *)X)[2 * (ix) + 1]);
    (((double *)Y)[2 * (iy)]) += (alpha_real * x_real1 - alpha_imag * x_imag1);
    (((double *)Y)[2 * (iy) + 1]) += (alpha_real * x_imag1 + alpha_imag * x_real1);

    if (i + 1 < N) {
        const double x_real2 = (((const double *)X)[2 * (ix + incX)]);
        const double x_imag2 = (((const double *)X)[2 * (ix + incX) + 1]);
        (((double *)Y)[2 * (iy + incY)]) += (alpha_real * x_real2 - alpha_imag * x_imag2);
        (((double *)Y)[2 * (iy + incY) + 1]) += (alpha_real * x_imag2 + alpha_imag * x_real2);
    }

    ix += 2 * incX;
    iy += 2 * incY;
}
}
