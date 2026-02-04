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
        float mem1 = alpha * mem + gain_scale_factor;
        float out_val1 = in[i] * mem1;
        mem = alpha * mem1 + gain_scale_factor;
        float out_val2 = (i+1 < size) ? in[i+1] * mem : 0.0f;
        out[i] = out_val1;
        if (i+1 < size) out[i+1] = out_val2;
    }
}
