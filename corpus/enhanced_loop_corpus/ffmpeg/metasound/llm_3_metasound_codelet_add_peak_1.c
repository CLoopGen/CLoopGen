#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float period;
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int len;
extern int i;
extern int j;
extern int center;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Gather) Memory Access via Index Array
    // Instead of direct j + center arithmetic, use an indirect lookup table for non-regular access patterns.
    // Simulates irregular access which might be useful in signal processing with variable spacing.

    // Precomputed index buffer (assumed to be allocated and valid for the working set)
    static int indices[1024]; // Assume max width * number of iterations is bounded
    for (i = 1; i < (((len) >= 0 ? (len) + ((width) >> 1) : (len) - ((width) >> 1)) / (width)); i++) {
        center = (int)(i * period + 0.5);
        // Precompute access indices for current center
        for (j = -width / 2; j < (width + 1) / 2; j++) {
            indices[j + width / 2] = j + center;
        }
        // Use indirect addressing
        for (j = 0; j < width; j++) {
            speech[indices[j]] += ppc_gain * (*shape++);
        }
    }
}
