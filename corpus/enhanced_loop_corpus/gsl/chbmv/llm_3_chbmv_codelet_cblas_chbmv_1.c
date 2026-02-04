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
const int stride = 2 * incY;
float* y_ptr = (float*)Y + 2 * iy;
for (i = 0; i < N; i++) {
    const float y_real = y_ptr[0];
    const float y_imag = y_ptr[1];
    const float tmpR = y_real * beta_real - y_imag * beta_imag;
    const float tmpI = y_real * beta_imag + y_imag * beta_real;
    y_ptr[0] = tmpR;
    y_ptr[1] = tmpI;
    y_ptr += stride;
    iy += incY;
}
}
