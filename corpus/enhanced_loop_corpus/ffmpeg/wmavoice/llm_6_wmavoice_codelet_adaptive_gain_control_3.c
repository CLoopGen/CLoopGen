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
    float temp_mem = mem;
    for (i = 0; i < size; i++) {
        temp_mem = alpha * temp_mem + gain_scale_factor;
        out[i] = in[i] * temp_mem;
    }
    mem = temp_mem;
}
