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
    float scale1 = gc_scale * 1.1f;
    float scale2 = gc_scale * 0.9f;
    for (pos = 0; pos < num_samples; pos++) {
        float temp = in[pos] * (pos % 2 ? scale1 : scale2);
        out[pos] = temp + prev[pos] * 1.05f - 0.05f * in[pos];
    }
}
