#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern  float beta_real;
extern  float beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        float y_real = (((float *)Y)[2 * (iy)]);
        float y_imag = (((float *)Y)[2 * (iy) + 1]);

        float acc_real = y_real;
        float acc_imag = y_imag;

        for (int j = 0; j < 3; j++) {
            acc_real = acc_real * beta_real - acc_imag * beta_imag;
            acc_imag = y_real * beta_imag + acc_imag * beta_real;
        }

        (((float *)Y)[2 * (iy)]) = acc_real;
        (((float *)Y)[2 * (iy) + 1]) = acc_imag;

        iy += incY;
    }
}
