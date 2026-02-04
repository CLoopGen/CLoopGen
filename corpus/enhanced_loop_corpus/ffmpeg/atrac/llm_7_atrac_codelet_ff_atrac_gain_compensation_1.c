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
    float acc = 0.0f;
    for (pos = 0; pos < num_samples; pos++) {
        acc += in[pos] * gc_scale;
        out[pos] = acc + prev[pos];
    }
}
