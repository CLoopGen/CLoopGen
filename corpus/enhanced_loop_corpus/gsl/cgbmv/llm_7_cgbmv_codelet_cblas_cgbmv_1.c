#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern  float beta_real;
extern  float beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *y_ptr = (float *)Y;
    float prev_tmpR = 0.0f, prev_tmpI = 0.0f;
    for (i = 0; i < lenY; i++) {
        int idx = 2 * iy;
        const float y_real = y_ptr[idx] + prev_tmpR; // Introduce RAW and loop-carried dependency
        const float y_imag = y_ptr[idx + 1] + prev_tmpI;
        const float tmpR = y_real * beta_real - y_imag * beta_imag;
        const float tmpI = y_real * beta_imag + y_imag * beta_real;
        y_ptr[idx] = tmpR;
        y_ptr[idx + 1] = tmpI;
        prev_tmpR = tmpR; // Create WAW and loop-carried dependence via prev variables
        prev_tmpI = tmpI;
        iy += incY;
    }
}
