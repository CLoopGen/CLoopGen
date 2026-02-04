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
    int i = pos;
    for (; i < num_samples; i++) {
        out[i] = in[i] * gc_scale + prev[i];
    }
}
