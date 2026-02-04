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
    for (i = 0; i < n; i++) {
        float local_tmp = gain * in[i] - pole_coeffs[0] * mem[0] - pole_coeffs[1] * mem[1];
        float local_out = local_tmp + zero_coeffs[0] * mem[0] + zero_coeffs[1] * mem[1];
        mem[1] = mem[0];
        mem[0] = local_tmp;
        out[i] = local_out;
    }
}
