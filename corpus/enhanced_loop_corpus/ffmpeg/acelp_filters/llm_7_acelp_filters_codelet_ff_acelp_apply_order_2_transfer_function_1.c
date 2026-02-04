#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in;
extern  float zero_coeffs[2];
extern  float pole_coeffs[2];
extern float gain;
extern float mem[2];
extern int n;
extern int i;
extern float tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_mem0, temp_mem1;
    temp_mem0 = mem[0];
    temp_mem1 = mem[1];
    for (i = 0; i < n; i++) {
        tmp = gain * in[i] - pole_coeffs[0] * temp_mem0 - pole_coeffs[1] * temp_mem1;
        out[i] = tmp + zero_coeffs[0] * temp_mem0 + zero_coeffs[1] * temp_mem1;
        temp_mem1 = temp_mem0;
        temp_mem0 = tmp;
    }
    mem[0] = temp_mem0;
    mem[1] = temp_mem1;
}
