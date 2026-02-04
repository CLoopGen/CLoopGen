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
    double temp_real = alpha_real * x_real - alpha_imag * x_imag;
    double temp_imag = alpha_real * x_imag + alpha_imag * x_real;

    // Introduce additional arithmetic to increase computational intensity
    temp_real = temp_real * 1.001 + 0.0001;
    temp_imag = temp_imag * 1.001 - 0.0001;

    (((double *)Y)[2 * (iy)]) += temp_real;
    (((double *)Y)[2 * (iy) + 1]) += temp_imag;

    ix += incX;
    iy += incY;
}
}
