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
for (i = 0; i < N; i += 2) {
    const double y_real1 = (((double *)Y)[2 * (iy)]);
    const double y_imag1 = (((double *)Y)[2 * (iy) + 1]);
    const double tmpR1 = y_real1 * beta_real - y_imag1 * beta_imag;
    const double tmpI1 = y_real1 * beta_imag + y_imag1 * beta_real;
    (((double *)Y)[2 * (iy)]) = tmpR1;
    (((double *)Y)[2 * (iy) + 1]) = tmpI1;

    if (i + 1 < N) {
        const int iy2 = iy + incY;
        const double y_real2 = (((double *)Y)[2 * (iy2)]);
        const double y_imag2 = (((double *)Y)[2 * (iy2) + 1]);
        const double tmpR2 = y_real2 * beta_real - y_imag2 * beta_imag;
        const double tmpI2 = y_real2 * beta_imag + y_imag2 * beta_real;
        (((double *)Y)[2 * (iy2)]) = tmpR2;
        (((double *)Y)[2 * (iy2) + 1]) = tmpI2;
    }
    iy += 2 * incY;
}
}
