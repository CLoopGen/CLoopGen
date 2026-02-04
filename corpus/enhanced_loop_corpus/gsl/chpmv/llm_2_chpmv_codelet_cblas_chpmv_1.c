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
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access via iy, we process elements consecutively in memory
    // assuming incY was originally a stride. We now access Y as a contiguous array of complex numbers.
    
    float *y_ptr = (float *)Y;
    for (i = 0; i < N; i++) {
        const float y_real = y_ptr[2 * i];
        const float y_imag = y_ptr[2 * i + 1];
        const float tmpR = y_real * beta_real - y_imag * beta_imag;
        const float tmpI = y_real * beta_imag + y_imag * beta_real;
        y_ptr[2 * i] = tmpR;
        y_ptr[2 * i + 1] = tmpI;
    }
}
