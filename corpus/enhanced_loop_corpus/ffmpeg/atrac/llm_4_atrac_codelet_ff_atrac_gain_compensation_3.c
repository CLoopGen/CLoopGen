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
    for (; pos < num_samples; pos++) {
        float temp = in[pos] * gc_scale;
        if (temp > 0.0f) {
            out[pos] = temp + prev[pos];
        } else {
            out[pos] = prev[pos];
        }
    }
}
