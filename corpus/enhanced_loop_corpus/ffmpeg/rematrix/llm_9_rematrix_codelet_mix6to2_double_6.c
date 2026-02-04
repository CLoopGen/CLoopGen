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
for (i = 0; i < len; i++) {
    double t = in[2][i] * (double)coeffp[0 * 6 + 2] + in[3][i] * (double)coeffp[0 * 6 + 3];
    double u0 = in[0][i] * (double)coeffp[0 * 6 + 0];
    double u1 = in[4][i] * (double)coeffp[0 * 6 + 4];
    double u2 = in[1][i] * (double)coeffp[1 * 6 + 1];
    double u3 = in[5][i] * (double)coeffp[1 * 6 + 5];

    out[0][i] = t + u0 + u1;
    out[1][i] = t + u2 + u3;

    // Additional computational workload to increase arithmetic intensity
    out[0][i] += out[0][i] * (double)coeffp[2 * 6 + 0];
    out[1][i] += out[1][i] * (double)coeffp[2 * 6 + 1];
}
}
