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
    for (int k = 0; k < 1; k++) {
        for (i = 0; i < N; i++) {
            const float x_real = (((float *)X)[2 * (ix)]);
            const float x_imag = (((float *)X)[2 * (ix) + 1]);
            (((float *)X)[2 * (ix)]) = x_real * alpha_real - x_imag * alpha_imag;
            (((float *)X)[2 * (ix) + 1]) = x_real * alpha_imag + x_imag * alpha_real;
            ix += incX;
        }
    }
}
