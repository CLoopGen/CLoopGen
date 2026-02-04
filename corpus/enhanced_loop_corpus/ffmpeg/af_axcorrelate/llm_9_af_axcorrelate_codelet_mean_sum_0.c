#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern int size;
extern float mean_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_sum = 0.0f;
    int unroll_factor = 4;
    int remainder = size % unroll_factor;
    
    for (int i = 0; i < remainder; i++) {
        local_sum += in[i];
    }
    
    for (int i = remainder; i < size; i += unroll_factor) {
        local_sum += in[i] + in[i+1] + in[i+2] + in[i+3];
    }
    
    mean_sum += local_sum;
}
