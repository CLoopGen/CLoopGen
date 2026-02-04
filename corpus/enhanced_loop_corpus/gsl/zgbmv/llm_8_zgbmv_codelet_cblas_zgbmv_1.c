#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern  double beta_real;
extern  double beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i += 2) {
    if (i + 1 < lenY) {
        const double y1_real = (((double *)Y)[2 * (iy)]);
        const double y1_imag = (((double *)Y)[2 * (iy) + 1]);
        const double y2_real = (((double *)Y)[2 * (iy + incY)]);
        const double y2_imag = (((double *)Y)[2 * (iy + incY) + 1]);

        const double tmp1R = y1_real * beta_real - y1_imag * beta_imag;
        const double tmp1I = y1_real * beta_imag + y1_imag * beta_real;
        const double tmp2R = y2_real * beta_real - y2_imag * beta_imag;
        const double tmp2I = y2_real * beta_imag + y2_imag * beta_real;

        (((double *)Y)[2 * (iy)]) = tmp1R;
        (((double *)Y)[2 * (iy) + 1]) = tmp1I;
        (((double *)Y)[2 * (iy + incY)]) = tmp2R;
        (((double *)Y)[2 * (iy + incY) + 1]) = tmp2I;
    } else {
        const double y_real = (((double *)Y)[2 * (iy)]);
        const double y_imag = (((double *)Y)[2 * (iy) + 1]);
        const double tmpR = y_real * beta_real - y_imag * beta_imag;
        const double tmpI = y_real * beta_imag + y_imag * beta_real;
        (((double *)Y)[2 * (iy)]) = tmpR;
        (((double *)Y)[2 * (iy) + 1]) = tmpI;
    }
    iy += 2 * incY;
}
}
