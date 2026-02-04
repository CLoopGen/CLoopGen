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
for (i = 0; i < len; i += 2) {
    float t0 = in[2][i] * (float)coeffp[0 * 6 + 2] + in[3][i] * (float)coeffp[0 * 6 + 3];
    out[0][i] = t0 + in[0][i] * (float)coeffp[0 * 6 + 0] + in[4][i] * (float)coeffp[0 * 6 + 4];
    out[1][i] = t0 + in[1][i] * (float)coeffp[1 * 6 + 1] + in[5][i] * (float)coeffp[1 * 6 + 5];

    if (i + 1 < len) {
        float t1 = in[2][i+1] * (float)coeffp[0 * 6 + 2] + in[3][i+1] * (float)coeffp[0 * 6 + 3];
        out[0][i+1] = t1 + in[0][i+1] * (float)coeffp[0 * 6 + 0] + in[4][i+1] * (float)coeffp[0 * 6 + 4];
        out[1][i+1] = t1 + in[1][i+1] * (float)coeffp[1 * 6 + 1] + in[5][i+1] * (float)coeffp[1 * 6 + 5];
    }
}
}
