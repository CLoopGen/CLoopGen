#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

typedef float UINTFLOAT;

extern INTFLOAT out[2][38][64];
extern INTFLOAT in[91][32][2];
extern int len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increase arithmetic operations per iteration with additional accumulations
for (n = 0; n < len; n++) {
    // Add more computation: accumulate over a larger set of inputs for higher intensity
    out[0][n][0] = (UINTFLOAT)in[0][n][0] + in[1][n][0] + in[2][n][0] + (UINTFLOAT)in[3][n][0] +
                   in[4][n][0] + in[5][n][0] + in[10][n][0] + in[11][n][0] + in[12][n][0];
    out[1][n][0] = (UINTFLOAT)in[0][n][1] + in[1][n][1] + in[2][n][1] + (UINTFLOAT)in[3][n][1] +
                   in[4][n][1] + in[5][n][1] + in[10][n][1] + in[11][n][1] + in[12][n][1];

    out[0][n][1] = (UINTFLOAT)in[6][n][0] + in[7][n][0] + in[13][n][0] + in[14][n][0];
    out[1][n][1] = (UINTFLOAT)in[6][n][1] + in[7][n][1] + in[13][n][1] + in[14][n][1];

    out[0][n][2] = (UINTFLOAT)in[8][n][0] + in[9][n][0] + in[15][n][0];
    out[1][n][2] = (UINTFLOAT)in[8][n][1] + in[9][n][1] + in[15][n][1];

    // Additional computation to further increase workload
    out[0][n][3] = (UINTFLOAT)in[16][n][0] - in[17][n][0];
    out[1][n][3] = (UINTFLOAT)in[16][n][1] - in[17][n][1];
}
}
