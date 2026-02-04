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
for (i = 0; i < N && N > 0; i++) {
    const float x_real = (((float *)X)[2 * (ix)]);
    const float x_imag = (((float *)X)[2 * (ix) + 1]);

    // Introduce additional arithmetic to increase computational intensity
    const float temp1 = x_real * alpha_real;
    const float temp2 = x_imag * alpha_imag;
    const float temp3 = x_real * alpha_imag;
    const float temp4 = x_imag * alpha_real;

    // Apply fused multiply-add approximation via expanded operations
    const float result_real = temp1 - temp2;
    const float result_imag = temp3 + temp4;

    // Store results with redundant temporary use to simulate higher register pressure
    (((float *)X)[2 * (ix)])     = result_real;
    (((float *)X)[2 * (ix) + 1]) = result_imag;

    ix += incX;
}
}
