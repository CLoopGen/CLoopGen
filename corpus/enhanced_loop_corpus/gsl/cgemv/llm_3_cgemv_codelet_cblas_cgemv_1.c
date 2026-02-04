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
    // Variant 2: Indirect Access via Index Array
    // Assume an auxiliary index array maps logical iteration to physical memory location.
    // This simulates indirect or gather-style access pattern.
    // We introduce a local static index array for demonstration (in practice, this could be passed).
    static int indices[1024]; // Assume maximum size; in real use, this would be dynamic or passed
    if (lenY > 1024) return; // Safety check for demo

    // Precompute indirect indices: map i -> position in Y based on iy and incY progression
    for (int j = 0; j < lenY; j++) {
        indices[j] = 2 * (iy + j * incY);
    }

    for (i = 0; i < lenY; i++) {
        const int phys_idx = indices[i]; // Indirect lookup
        const float y_real = ((float*)Y)[phys_idx];
        const float y_imag = ((float*)Y)[phys_idx + 1];
        const float tmpR = y_real * beta_real - y_imag * beta_imag;
        const float tmpI = y_real * beta_imag + y_imag * beta_real;
        ((float*)Y)[phys_idx] = tmpR;
        ((float*)Y)[phys_idx + 1] = tmpI;
    }
}
