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
    float temp;
    for (int i = pos; i < num_samples; i++) {
        temp = in[i] * gc_scale;
        out[i] = temp + prev[i];
    }
}
