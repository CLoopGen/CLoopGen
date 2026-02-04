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
for (i = 0; i < len; i += 2) {
    double t0 = in[2][i] * (double)coeffp[0 * 8 + 2] + in[3][i] * (double)coeffp[0 * 8 + 3];
    double t1 = (i+1 < len) ? in[2][i+1] * (double)coeffp[0 * 8 + 2] + in[3][i+1] * (double)coeffp[0 * 8 + 3] : 0.0;

    out[0][i] = t0 + in[0][i] * (double)coeffp[0 * 8 + 0] + in[4][i] * (double)coeffp[0 * 8 + 4] + in[6][i] * (double)coeffp[0 * 8 + 6];
    out[1][i] = t0 + in[1][i] * (double)coeffp[1 * 8 + 1] + in[5][i] * (double)coeffp[1 * 8 + 5] + in[7][i] * (double)coeffp[1 * 8 + 7];

    if (i+1 < len) {
        out[0][i+1] = t1 + in[0][i+1] * (double)coeffp[0 * 8 + 0] + in[4][i+1] * (double)coeffp[0 * 8 + 4] + in[6][i+1] * (double)coeffp[0 * 8 + 6];
        out[1][i+1] = t1 + in[1][i+1] * (double)coeffp[1 * 8 + 1] + in[5][i+1] * (double)coeffp[1 * 8 + 5] + in[7][i+1] * (double)coeffp[1 * 8 + 7];
    }
}
}
