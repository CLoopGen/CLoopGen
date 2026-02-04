#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int j;
extern  float *shape_end;
extern int center;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed index
    // Instead of incrementing pointer 'shape' and computing 'j + center' repeatedly,
    // we calculate the base index and access speech consecutively.
    int start_idx = center - width / 2;
    float *sptr = &speech[start_idx];
    for (int i = 0; i < width && shape < shape_end; i++) {
        sptr[i] += ppc_gain * shape[i];
    }
}
