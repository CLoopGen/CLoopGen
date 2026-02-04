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
    const float y_real = (((float *)Y)[2 * (iy)]);
    const float y_imag = (((float *)Y)[2 * (iy) + 1]);
    const float br = beta_real;
    const float bi = beta_imag;
    const float tmpR = y_real * br - y_imag * bi;
    const float tmpI = y_real * bi + y_imag * br;
    ((float *)Y)[2 * (iy)] = tmpR;
    ((float *)Y)[2 * (iy) + 1] = tmpI;
    
    // Additional computational work to increase arithmetic intensity
    float accumulator = 0.0f;
    for (int j = 0; j < 4; ++j) {
        accumulator += tmpR * tmpI + br * bi;
    }
    ((float *)Y)[2 * (iy)] += accumulator * 0.1f;

    iy += incY;
}
}
