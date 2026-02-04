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
int stride = 4;
for (i = 0; i < len; i += stride) {
    for (int s = 0; s < stride; s++) {
        int idx = i + s;
        if (idx >= len) break;
        float t = in[2][idx] * (float)coeffp[0 * 8 + 2] + in[3][idx] * (float)coeffp[0 * 8 + 3];
        out[0][idx] = t + in[0][idx] * (float)coeffp[0 * 8 + 0] + in[4][idx] * (float)coeffp[0 * 8 + 4] + in[6][idx] * (float)coeffp[0 * 8 + 6];
        out[1][idx] = t + in[1][idx] * (float)coeffp[1 * 8 + 1] + in[5][idx] * (float)coeffp[1 * 8 + 5] + in[7][idx] * (float)coeffp[1 * 8 + 7];
    }
}
}
