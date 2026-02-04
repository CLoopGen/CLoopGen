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

    // Increased arithmetic intensity: simulate a small accumulation over unrolled micro-steps
    float temp_real = 0.0f, temp_imag = 0.0f;
    for (int k = 0; k < 3; k++) {
        temp_real += (x_real * y_real - x_imag * y_imag) * 0.5f;
        temp_imag += (x_real * y_imag + x_imag * y_real) * 0.5f;
    }

    r_real += temp_real;
    r_imag += temp_imag;

    ix += incX;
    iy += incY;
}
}
