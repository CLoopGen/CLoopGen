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
int i_inner;
for (i = 0; i < lenY; i++) {
    for (i_inner = 0; i_inner < 1; i_inner++) {
        const double y_real = (((double *)Y)[2 * (iy)]);
        const double y_imag = (((double *)Y)[2 * (iy) + 1]);
        const double tmpR = y_real * beta_real - y_imag * beta_imag;
        const double tmpI = y_real * beta_imag + y_imag * beta_real;
        (((double *)Y)[2 * (iy)]) = tmpR;
        (((double *)Y)[2 * (iy) + 1]) = tmpI;
        iy += incY;
    }
}
}
