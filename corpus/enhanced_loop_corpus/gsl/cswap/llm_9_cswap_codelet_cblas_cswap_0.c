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
for (i = 0; i < N && i < 64; i++) {
    const float tmp_real = (((float *)X)[2 * (ix)]);
    const float tmp_imag = (((float *)X)[2 * (ix) + 1]);
    float y_val_real = (((float *)Y)[2 * (iy)]);
    float y_val_imag = (((float *)Y)[2 * (iy) + 1]);

    // Additional arithmetic to increase computational intensity
    y_val_real = (y_val_real + tmp_real) * 0.5f;
    y_val_imag = (y_val_imag + tmp_imag) * 0.5f;

    (((float *)X)[2 * (ix)]) = y_val_real;
    (((float *)X)[2 * (ix) + 1]) = y_val_imag;
    (((float *)Y)[2 * (iy)]) = tmp_real;
    (((float *)Y)[2 * (iy) + 1]) = tmp_imag;

    ix += incX;
    iy += incY;
}
}
