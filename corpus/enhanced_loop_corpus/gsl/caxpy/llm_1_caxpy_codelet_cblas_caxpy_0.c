#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    for (int j = 0; j < 2 && (i + j) < N; j++) {
        const int curr_i = i + j;
        const int curr_ix = ix + j * incX;
        const int curr_iy = iy + j * incY;
        const float x_real = (((const float *)X)[2 * curr_ix]);
        const float x_imag = (((const float *)X)[2 * curr_ix + 1]);
        (((float *)Y)[2 * curr_iy]) += (alpha_real * x_real - alpha_imag * x_imag);
        (((float *)Y)[2 * curr_iy + 1]) += (alpha_real * x_imag + alpha_imag * x_real);
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
