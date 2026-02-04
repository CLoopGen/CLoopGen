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
    float prev_mem = mem;
    for (i = 0; i < size; i++) {
        float curr_mem = alpha * prev_mem + gain_scale_factor;
        out[i] = in[i] * curr_mem;
        prev_mem = curr_mem;
    }
    mem = prev_mem;
}
