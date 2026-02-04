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
    for (i = pos; i < num_samples; i += 2) {
        float temp1 = in[i] * gc_scale + prev[i];
        float temp2 = (i + 1 < num_samples) ? (in[i+1] * gc_scale + prev[i+1]) : 0.0f;
        out[i] = temp1;
        if (i + 1 < num_samples) {
            out[i+1] = temp2;
        }
    }
    pos = i;
}
