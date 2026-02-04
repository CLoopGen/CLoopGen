#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern float **out;
extern  float **in;
extern float *coeffp;
extern integer len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Layout Simulation via Pointer Arithmetic
    // Assume data is laid out consecutively in memory for input and output planes
    float *in0 = in[0], *in1 = in[1], *in2 = in[2], *in3 = in[3], *in4 = in[4], *in5 = in[5];
    float *out0 = out[0], *out1 = out[1];

    // Precompute coefficient offsets
    float c00 = (float)coeffp[0 * 6 + 0];
    float c02 = (float)coeffp[0 * 6 + 2];
    float c03 = (float)coeffp[0 * 6 + 3];
    float c04 = (float)coeffp[0 * 6 + 4];
    float c11 = (float)coeffp[1 * 6 + 1];
    float c15 = (float)coeffp[1 * 6 + 5];

    for (i = 0; i < len; i++) {
        float t = in2[i] * c02 + in3[i] * c03;
        out0[i] = t + in0[i] * c00 + in4[i] * c04;
        out1[i] = t + in1[i] * c11 + in5[i] * c15;
    }
}
