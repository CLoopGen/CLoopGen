#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern double **out;
extern  double **in;
extern double *coeffp;
extern integer len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double prev_out0 = 0.0;
for (i = 0; i < len; i++) {
    double t = in[2][i] * (double)coeffp[0 * 8 + 2] + in[3][i] * (double)coeffp[0 * 8 + 3];
    double temp_out0 = t + in[0][i] * (double)coeffp[0 * 8 + 0] + in[4][i] * (double)coeffp[0 * 8 + 4] + in[6][i] * (double)coeffp[0 * 8 + 6];
    out[0][i] = temp_out0 + prev_out0; // Introduce WAW and loop-carried dependency
    out[1][i] = t + in[1][i] * (double)coeffp[1 * 8 + 1] + in[5][i] * (double)coeffp[1 * 8 + 5] + in[7][i] * (double)coeffp[1 * 8 + 7];
    prev_out0 = temp_out0;
}
}
