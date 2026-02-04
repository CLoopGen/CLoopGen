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
for (i = 0; i < len; i++) {
    int t = in[2][i] * (int)coeffp[0 * 6 + 2] + in[3][i] * (int)coeffp[0 * 6 + 3];
    int base0 = in[0][i] * (int)coeffp[0 * 6 + 0];
    int base1 = in[1][i] * (int)coeffp[1 * 6 + 1];
    int extra4 = in[4][i] * (int)coeffp[0 * 6 + 4];
    int extra5 = in[5][i] * (int)coeffp[1 * 6 + 5];
    int sum0 = t + base0 + extra4;
    int sum1 = t + base1 + extra5;
    out[0][i] = ((sum0 + 16384) >> 15);
    out[1][i] = ((sum1 + 16384) >> 15);
}
}
