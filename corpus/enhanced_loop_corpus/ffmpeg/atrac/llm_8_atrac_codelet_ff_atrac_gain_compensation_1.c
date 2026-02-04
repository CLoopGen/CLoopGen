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
    for (pos = 0; pos < num_samples; pos += 2) {
        if (pos + 1 < num_samples) {
            out[pos] = in[pos] * gc_scale + prev[pos];
            out[pos + 1] = in[pos + 1] * gc_scale + prev[pos + 1];
        } else {
            out[pos] = in[pos] * gc_scale + prev[pos];
        }
    }
}
