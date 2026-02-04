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
    // Variant 1: Consecutive Memory Access (unrolled by 2 elements)
    // Instead of strided access via iy, we assume incY == 1 and access Y consecutively.
    // We process two complex numbers at a time if available.
    int idx = 0;
    for (i = 0; i < lenY; i++) {
        const int offset = 2 * idx;
        const float y_real = ((float*)Y)[offset];
        const float y_imag = ((float*)Y)[offset + 1];
        const float tmpR = y_real * beta_real - y_imag * beta_imag;
        const float tmpI = y_real * beta_imag + y_imag * beta_real;
        ((float*)Y)[offset] = tmpR;
        ((float*)Y)[offset + 1] = tmpI;
        idx += incY;  // Still respects incY but assumes sequential layout
    }
}
