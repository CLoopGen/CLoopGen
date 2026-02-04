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
    int chunk_size = 4;
    int i;
    for (i = pos; i <= num_samples - chunk_size; i += chunk_size) {
        out[i] = in[i] * gc_scale + prev[i];
        out[i+1] = in[i+1] * gc_scale + prev[i+1];
        out[i+2] = in[i+2] * gc_scale + prev[i+2];
        out[i+3] = in[i+3] * gc_scale + prev[i+3];
    }
    for (; i < num_samples; i++) {
        out[i] = in[i] * gc_scale + prev[i];
    }
}
