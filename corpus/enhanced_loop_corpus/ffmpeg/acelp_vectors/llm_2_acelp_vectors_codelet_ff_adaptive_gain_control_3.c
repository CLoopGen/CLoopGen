#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in;
extern int size;
extern float alpha;
extern int i;
extern float gain_scale_factor;
extern float mem;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < size; i += 2) {
    mem = alpha * mem + gain_scale_factor;
    out[i] = in[i] * mem;
    if (i + 1 < size) {
        mem = alpha * mem + gain_scale_factor;
        out[i + 1] = in[i + 1] * mem;
    }
}
}
