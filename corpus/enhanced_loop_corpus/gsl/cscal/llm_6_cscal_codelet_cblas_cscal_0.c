#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *X;
extern  int incX;
extern int i;
extern int ix;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_real = 0.0f, prev_imag = 0.0f;
    for (i = 0; i < N; i++) {
        const float x_real = (((float *)X)[2 * (ix)]);
        const float x_imag = (((float *)X)[2 * (ix) + 1]);
        const float temp_real = x_real * alpha_real - x_imag * alpha_imag;
        const float temp_imag = x_real * alpha_imag + x_imag * alpha_real;
        // Introduce WAW and RAW dependencies by using previous iteration's output
        ((float*)X)[2 * ix] = (i == 0) ? temp_real : temp_real + prev_real;
        ((float*)X)[2 * ix + 1] = (i == 0) ? temp_imag : temp_imag + prev_imag;
        prev_real = ((float*)X)[2 * ix];
        prev_imag = ((float*)X)[2 * ix + 1];
        ix += incX;
    }
}
