#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        const double tmp_real = (((double *)X)[2 * (ix)]);
        const double tmp_imag = (((double *)X)[2 * (ix) + 1]);

        if (tmp_real >= 0.0) {
            (((double *)X)[2 * (ix)]) = (((double *)Y)[2 * (iy)]);
            (((double *)X)[2 * (ix) + 1]) = (((double *)Y)[2 * (iy) + 1]);
            (((double *)Y)[2 * (iy)]) = tmp_real;
            (((double *)Y)[2 * (iy) + 1]) = tmp_imag;
        } else {
            (((double *)Y)[2 * (iy)]) = (((double *)X)[2 * (ix)]);
            (((double *)Y)[2 * (iy) + 1]) = (((double *)X)[2 * (ix) + 1]);
            (((double *)X)[2 * (ix)]) = tmp_real;
            (((double *)X)[2 * (ix) + 1]) = tmp_imag;
        }

        ix += incX;
        iy += incY;
    }
}
