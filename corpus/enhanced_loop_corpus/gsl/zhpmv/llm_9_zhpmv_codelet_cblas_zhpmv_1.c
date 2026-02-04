#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern  double beta_real;
extern  double beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const double y_real = (((double *)Y)[2 * (iy)]);
    const double y_imag = (((double *)Y)[2 * (iy) + 1]);

    // Increased arithmetic intensity: simulate additional computation (e.g., extra scaling and addition)
    const double scale = 1.5;
    const double offset_real = 0.1;
    const double offset_imag = -0.1;

    const double scaled_y_real = y_real * scale;
    const double scaled_y_imag = y_imag * scale;

    const double tmpR = (scaled_y_real * beta_real - scaled_y_imag * beta_imag) + offset_real;
    const double tmpI = (scaled_y_real * beta_imag + scaled_y_imag * beta_real) + offset_imag;

    (((double *)Y)[2 * (iy)]) = tmpR;
    (((double *)Y)[2 * (iy) + 1]) = tmpI;
    iy += incY;
}
}
