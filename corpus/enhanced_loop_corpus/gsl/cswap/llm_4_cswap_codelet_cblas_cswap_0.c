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
        if (i % 2 == 0) {
            const float tmp_real = (((float *)X)[2 * (ix)]);
            const float tmp_imag = (((float *)X)[2 * (ix) + 1]);
            (((float *)X)[2 * (ix)]) = (((float *)Y)[2 * (iy)]);
            (((float *)X)[2 * (ix) + 1]) = (((float *)Y)[2 * (iy) + 1]);
            (((float *)Y)[2 * (iy)]) = tmp_real;
            (((float *)Y)[2 * (iy) + 1]) = tmp_imag;
        } else {
            const float tmp_real = (((float *)Y)[2 * (iy)]);
            const float tmp_imag = (((float *)Y)[2 * (iy) + 1]);
            (((float *)Y)[2 * (iy)]) = (((float *)X)[2 * (ix)]);
            (((float *)Y)[2 * (iy) + 1]) = (((float *)X)[2 * (ix) + 1]);
            (((float *)X)[2 * (ix)]) = tmp_real;
            (((float *)X)[2 * (ix) + 1]) = tmp_imag;
        }
        ix += incX;
        iy += incY;
    }
}
