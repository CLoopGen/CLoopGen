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
    double t0 = in[2][i] * (double)coeffp[0 * 8 + 2] + in[3][i] * (double)coeffp[0 * 8 + 3];
    double t1 = in[0][i] * (double)coeffp[0 * 8 + 0] + in[4][i] * (double)coeffp[0 * 8 + 4];
    double t2 = in[6][i] * (double)coeffp[0 * 8 + 6];
    out[0][i] = t0 + t1 + t2;

    double u1 = in[1][i] * (double)coeffp[1 * 8 + 1] + in[5][i] * (double)coeffp[1 * 8 + 5];
    double u2 = in[7][i] * (double)coeffp[1 * 8 + 7];
    out[1][i] = t0 + u1 + u2;
}
}
