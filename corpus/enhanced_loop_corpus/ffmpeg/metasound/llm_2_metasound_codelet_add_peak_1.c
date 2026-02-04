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
    // Variant 1: Consecutive Memory Access with Prefetched Indices
    // Modified to access speech in a consecutive, forward-only manner by precomputing indices.
    // This improves cache locality compared to random or strided access.

    int base_index = -width / 2;
    for (i = 1; i < (((len) >= 0 ? (len) + ((width) >> 1) : (len) - ((width) >> 1)) / (width)); i++) {
        center = (int)(i * period + 0.5);
        int start_idx = center + base_index;
        float *speech_ptr = &speech[start_idx];
        for (j = 0; j < width; j++) {
            speech_ptr[j] += ppc_gain * shape[i * width + j];  // Stride through shape with fixed offset per i
        }
    }
}
