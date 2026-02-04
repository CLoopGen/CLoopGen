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
    for (i = 0; i < N; i += 2) {
        for (int j = 0; j < 2 && (i + j) < N; j++) {
            const int current_ix = ix + j * incX;
            const float x_real = (((float *)X)[2 * current_ix]);
            const float x_imag = (((float *)X)[2 * current_ix + 1]);
            (((float *)X)[2 * current_ix]) = x_real * alpha_real - x_imag * alpha_imag;
            (((float *)X)[2 * current_ix + 1]) = x_real * alpha_imag + x_imag * alpha_real;
        }
        ix += 2 * incX;
    }
}
