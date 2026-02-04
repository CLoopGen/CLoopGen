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
    // Variant 2: Strided Memory Access with Fixed Stride Multiplier
    // Simulate a more regular strided pattern by using a fixed stride derived from incY,
    // but restructure the index calculation to emphasize stride-based traversal.
    // This variant maintains the original logic but expresses access in terms of a base offset and stride.
    float *base_Y = (float *)Y;
    const int stride_in_floats = 2 * incY; // Each complex number has 2 floats, scaled by incY
    int current_offset = 2 * iy; // Initial offset in float units

    for (i = 0; i < N; i++) {
        const float y_real = base_Y[current_offset];
        const float y_imag = base_Y[current_offset + 1];
        const float tmpR = y_real * beta_real - y_imag * beta_imag;
        const float tmpI = y_real * beta_imag + y_imag * beta_real;
        base_Y[current_offset] = tmpR;
        base_Y[current_offset + 1] = tmpI;
        current_offset += stride_in_floats;
    }
}
