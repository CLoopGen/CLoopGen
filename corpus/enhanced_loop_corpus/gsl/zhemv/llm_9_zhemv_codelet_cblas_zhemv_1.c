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

    const double beta_sq = beta_real * beta_real + beta_imag * beta_imag;
    const double scale = beta_sq > 1e-10 ? 1.0 / beta_sq : 1.0;

    const double tmpR = (y_real * beta_real + y_imag * beta_imag) * scale;
    const double tmpI = (y_imag * beta_real - y_real * beta_imag) * scale;

    (((double *)Y)[2 * (iy)]) = tmpR;
    (((double *)Y)[2 * (iy) + 1]) = tmpI;

    iy += incY;
}
}
