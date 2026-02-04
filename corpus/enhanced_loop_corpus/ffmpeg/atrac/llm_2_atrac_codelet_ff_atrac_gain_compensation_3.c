#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern float *prev;
extern int num_samples;
extern float *out;
extern float gc_scale;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (int i = pos; i < num_samples; i += 2) {
        out[i] = in[i] * gc_scale + prev[i];
        if (i + 1 < num_samples) {
            out[i + 1] = in[i + 1] * gc_scale + prev[i + 1];
        }
    }
}
