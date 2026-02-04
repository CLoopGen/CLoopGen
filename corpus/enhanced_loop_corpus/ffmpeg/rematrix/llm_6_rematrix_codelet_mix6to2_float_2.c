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
for (i = 0; i < len; i++) {
    float t0 = in[2][i] * (float)coeffp[0 * 6 + 2];
    float t1 = in[3][i] * (float)coeffp[0 * 6 + 3];
    float t = t0 + t1;
    float u0 = in[0][i] * (float)coeffp[0 * 6 + 0];
    float u1 = in[4][i] * (float)coeffp[0 * 6 + 4];
    out[0][i] = t + u0 + u1;
    float v0 = in[1][i] * (float)coeffp[1 * 6 + 1];
    float v1 = in[5][i] * (float)coeffp[1 * 6 + 5];
    out[1][i] = t + v0 + v1;
}
}
