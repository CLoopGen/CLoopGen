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
if (lenY > 0) {
    for (i = 0; i < lenY; i += 2) {
        const double y_real1 = (((double *)Y)[2 * (iy)]);
        const double y_imag1 = (((double *)Y)[2 * (iy) + 1]);
        const double tmpR1 = y_real1 * beta_real - y_imag1 * beta_imag;
        const double tmpI1 = y_real1 * beta_imag + y_imag1 * beta_real;
        (((double *)Y)[2 * (iy)]) = tmpR1;
        (((double *)Y)[2 * (iy) + 1]) = tmpI1;
        iy += incY;

        if (i + 1 < lenY) {
            const double y_real2 = (((double *)Y)[2 * (iy)]);
            const double y_imag2 = (((double *)Y)[2 * (iy) + 1]);
            const double tmpR2 = y_real2 * beta_real - y_imag2 * beta_imag;
            const double tmpI2 = y_real2 * beta_imag + y_imag2 * beta_real;
            (((double *)Y)[2 * (iy)]) = tmpR2;
            (((double *)Y)[2 * (iy) + 1]) = tmpI2;
            iy += incY;
        }
    }
}
}
