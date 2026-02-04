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
for (; pos < num_samples; pos++)
    out[pos] = in[pos] * gc_scale + prev[pos];

}
