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
    float acc_real = 0.0f, acc_imag = 0.0f;
    int local_ix = ix;
    int local_iy = iy;
    for (i = 0; i < N; i++) {
        const float x_real = (((const float *)X)[2 * local_ix]);
        const float x_imag = (((const float *)X)[2 * local_ix + 1]);
        acc_real += alpha_real * x_real - alpha_imag * x_imag;
        acc_imag += alpha_real * x_imag + alpha_imag * x_real;
        local_ix += incX;
    }
    (((float *)Y)[2 * iy]) += acc_real;
    (((float *)Y)[2 * iy + 1]) += acc_imag;
    ix += incX * N;
    iy += incY * N;
}
