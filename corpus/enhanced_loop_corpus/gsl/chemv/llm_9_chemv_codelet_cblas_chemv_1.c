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
    float *y_ptr = &(((float *)Y)[2 * iy]);
    const float y_real = y_ptr[0];
    const float y_imag = y_ptr[1];

    // Increased arithmetic intensity: apply scaling and add an extra rotation-like operation
    const float tmpR = (y_real * beta_real - y_imag * beta_imag) * 1.5f;
    const float tmpI = (y_real * beta_imag + y_imag * beta_real) * 1.5f;

    // Additional computational step: feedback-like update with neighbor (wrap-around)
    int next_iy = (iy + incY) % N;
    float *next_y_ptr = &(((float *)Y)[2 * next_iy]);
    const float neighbor_real = next_y_ptr[0];
    const float neighbor_imag = next_y_ptr[1];
    const float corrR = tmpR + 0.1f * (neighbor_real - tmpR);
    const float corrI = tmpI + 0.1f * (neighbor_imag - tmpI);

    y_ptr[0] = corrR;
    y_ptr[1] = corrI;

    iy += incY;
}
}
