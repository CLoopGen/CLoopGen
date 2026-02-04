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
    for (pos = 0; pos < num_samples; pos++) {
        float temp = in[pos] * gc_scale;
        if (temp > 1.0f) {
            out[pos] = prev[pos] + 1.0f;
        } else {
            out[pos] = temp + prev[pos];
        }
    }
}
