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
    float t = in[2][i] * (float)coeffp[0 * 8 + 2] + in[3][i] * (float)coeffp[0 * 8 + 3];
    float sum0 = in[0][i] * (float)coeffp[0 * 8 + 0];
    float sum1 = in[1][i] * (float)coeffp[1 * 8 + 1];
    
    for (int j = 0; j < 4; j += 2) {
        sum0 += in[4+j][i] * (float)coeffp[0 * 8 + 4 + j];
        sum1 += in[5+j][i] * (float)coeffp[1 * 8 + 5 + j];
    }
    
    out[0][i] = t + sum0;
    out[1][i] = t + sum1;
}
}
