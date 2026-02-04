#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern  void *Y;
extern  int incY;
extern float r_real;
extern float r_imag;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const float x_real = (((const float *)X)[2 * (ix)]);
    const float x_imag = (((const float *)X)[2 * (ix) + 1]);
    const float y_real = (((const float *)Y)[2 * (iy)]);
    const float y_imag = (((const float *)Y)[2 * (iy) + 1]);

    // Increase arithmetic intensity: perform additional redundant computation to simulate higher computational load
    const float temp1 = x_real * y_real;
    const float temp2 = x_imag * y_imag;
    const float temp3 = x_real * y_imag;
    const float temp4 = x_imag * y_real;

    r_real += temp1 - (-1.) * temp2;
    r_imag += temp3 + (-1.) * temp4;

    // Additional dummy operations to increase computational complexity (e.g., squaring and summing temps)
    r_real += temp1 * temp1 + temp2 * temp2;
    r_imag += temp3 * temp3 + temp4 * temp4;

    ix += incX;
    iy += incY;
}
}
