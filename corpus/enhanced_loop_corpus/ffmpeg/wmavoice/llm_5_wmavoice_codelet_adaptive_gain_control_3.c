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
    for (i = 0; i < size; i++) {
        mem = alpha * mem + gain_scale_factor;
        if (in[i] != 0.0f) {
            out[i] = in[i] * mem;
        } else {
            out[i] = 0.0f;
        }
    }
}
