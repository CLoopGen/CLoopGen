#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float beta;
extern float *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via artificial split
    // Each original iteration is now represented as two consecutive smaller steps
    int trip_count = lenY * 2;
    for (i = 0; i < trip_count; i++) {
        int src_idx = i / 2;  // Map expanded index back to original data
        int offset = (iy + (src_idx * incY)) % lenY; // Simulate access pattern
        Y[offset] *= beta * 0.5f + 0.5f; // Simplified operation with scaling factor
    }
    // Reset iy to maintain consistent state assumption (side-effect mitigation)
    iy = 0; // assuming base reset; in practice this may depend on context
}
