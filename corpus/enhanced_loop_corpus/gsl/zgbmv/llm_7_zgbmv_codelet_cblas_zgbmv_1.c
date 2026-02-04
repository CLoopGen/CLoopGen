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
    double temp_real[2] = {0}, temp_imag[2] = {0};
    int offset;
    for (i = 0; i < lenY; i++) {
        offset = 2 * (iy);
        temp_real[i & 1] = (((double *)Y)[offset]);
        temp_imag[i & 1] = (((double *)Y)[offset + 1]);

        const double y_real = temp_real[i & 1];
        const double y_imag = temp_imag[i & 1];
        const double tmpR = y_real * beta_real - y_imag * beta_imag;
        const double tmpI = y_real * beta_imag + y_imag * beta_real;

        (((double *)Y)[offset]) = tmpR;
        (((double *)Y)[offset + 1]) = tmpI;

        iy += incY;
    }
}
