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
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    int stride = 2;
    // First pass: process elements with stride
    for (i = 0; i < len; i += stride) {
        float t = in[2][i] * (float)coeffp[0 * 6 + 2] + in[3][i] * (float)coeffp[0 * 6 + 3];
        out[0][i] = t + in[0][i] * (float)coeffp[0 * 6 + 0] + in[4][i] * (float)coeffp[0 * 6 + 4];
        out[1][i] = t + in[1][i] * (float)coeffp[1 * 6 + 1] + in[5][i] * (float)coeffp[1 * 6 + 5];
    }
    // Second pass: handle odd indices if len is not multiple of stride
    for (i = 1; i < len; i += stride) {
        float t = in[2][i] * (float)coeffp[0 * 6 + 2] + in[3][i] * (float)coeffp[0 * 6 + 3];
        out[0][i] = t + in[0][i] * (float)coeffp[0 * 6 + 0] + in[4][i] * (float)coeffp[0 * 6 + 4];
        out[1][i] = t + in[1][i] * (float)coeffp[1 * 6 + 1] + in[5][i] * (float)coeffp[1 * 6 + 5];
    }
}
