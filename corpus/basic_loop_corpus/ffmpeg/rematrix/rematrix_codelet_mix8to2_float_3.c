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
    out[0][i] = t + in[0][i] * (float)coeffp[0 * 8 + 0] + in[4][i] * (float)coeffp[0 * 8 + 4] + in[6][i] * (float)coeffp[0 * 8 + 6];
    out[1][i] = t + in[1][i] * (float)coeffp[1 * 8 + 1] + in[5][i] * (float)coeffp[1 * 8 + 5] + in[7][i] * (float)coeffp[1 * 8 + 7];
}

}
