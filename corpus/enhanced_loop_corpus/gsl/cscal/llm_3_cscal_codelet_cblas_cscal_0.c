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
    // Variant 2: Strided access with explicit stride multiplication
    // Use incX as a full stride multiplier on index, simulating large step through data
    // This increases the gap between accessed elements, maintaining original ix logic but emphasizing stride
    float *x_ptr = (float *)X;
    for (i = 0; i < N; i++) {
        int offset = 2 * ix; // Base offset in float array
        const float x_real = x_ptr[offset];
        const float x_imag = x_ptr[offset + 1];
        x_ptr[offset]     = x_real * alpha_real - x_imag * alpha_imag;
        x_ptr[offset + 1] = x_real * alpha_imag + x_imag * alpha_real;
        ix += incX; // Stride remains user-defined, potentially large
    }
}
