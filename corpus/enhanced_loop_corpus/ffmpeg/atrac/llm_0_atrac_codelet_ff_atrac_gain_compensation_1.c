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
    int i;
    for (i = 0; i < num_samples; i += 4) {
        out[i] = in[i] * gc_scale + prev[i];
        if (i + 1 < num_samples)
            out[i + 1] = in[i + 1] * gc_scale + prev[i + 1];
        if (i + 2 < num_samples)
            out[i + 2] = in[i + 2] * gc_scale + prev[i + 2];
        if (i + 3 < num_samples)
            out[i + 3] = in[i + 3] * gc_scale + prev[i + 3];
    }
}
