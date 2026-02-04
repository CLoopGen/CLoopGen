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
    float *Y_ptr = (float *)Y;
    for (i = 0; i < N; i++) {
        const int idx = 2 * iy;
        const float y_real = Y_ptr[idx];
        const float y_imag = Y_ptr[idx + 1];
        const float tmpR = y_real * beta_real - y_imag * beta_imag;
        const float tmpI = y_real * beta_imag + y_imag * beta_real;
        Y_ptr[idx] = tmpR;
        Y_ptr[idx + 1] = tmpI;
        iy += incY;
    }
}
