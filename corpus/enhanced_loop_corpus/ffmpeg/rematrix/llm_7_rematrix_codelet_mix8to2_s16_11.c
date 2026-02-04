#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int16_t **out;
extern  int16_t **in;
extern int *coeffp;
extern integer len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_out0 = 0;
for (i = 0; i < len; i++) {
    int t = in[2][i] * (int)coeffp[0 * 8 + 2] + in[3][i] * (int)coeffp[0 * 8 + 3];
    int sum0 = t + in[0][i] * (int)coeffp[0 * 8 + 0] + in[4][i] * (int)coeffp[0 * 8 + 4] + in[6][i] * (int)coeffp[0 * 8 + 6];
    int sum1 = t + in[1][i] * (int)coeffp[1 * 8 + 1] + in[5][i] * (int)coeffp[1 * 8 + 5] + in[7][i] * (int)coeffp[1 * 8 + 7];

    out[0][i] = ((sum0 + 16384) >> 15);
    out[1][i] = ((sum1 + prev_out0 + 16384) >> 15);

    prev_out0 = out[0][i];
}
}
