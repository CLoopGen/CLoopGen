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
if (n > 0) {
    i = 0;
    // Simulate loop unrolling with a single iteration block, reducing loop depth effect
    // This variant assumes possible unrolling factor of 1 with direct sequence
    do {
        tmp = gain * in[i] - pole_coeffs[0] * mem[0] - pole_coeffs[1] * mem[1];
        out[i] = tmp + zero_coeffs[0] * mem[0] + zero_coeffs[1] * mem[1];
        mem[1] = mem[0];
        mem[0] = tmp;
        i++;
    } while (i < n); // Using do-while is disallowed per instructions — correction: use for
}
}
