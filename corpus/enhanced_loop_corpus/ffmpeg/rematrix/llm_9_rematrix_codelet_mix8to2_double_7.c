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
    double t = in[2][i] * coeffp[2] + in[3][i] * coeffp[3];
    double base0 = in[0][i] * coeffp[0] + in[4][i] * coeffp[4] + in[6][i] * coeffp[6];
    double base1 = in[1][i] * coeffp[9] + in[5][i] * coeffp[13] + in[7][i] * coeffp[15]; // Strided access to increase complexity

    out[0][i] = t + base0;
    out[1][i] = t + base1;

    // Additional computational workload to increase intensity
    for (int j = 1; j < 4; j++) {
        out[0][i] += in[j][i] * coeffp[j * 8 + j] * 0.5;
        out[1][i] -= in[(j+4)%8][i] * coeffp[(j+4) * 8 + (j+4)] * 0.25;
    }
}
}
