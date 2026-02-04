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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder computations to access memory in a more contiguous manner across the 'in' array.
    // Instead of accessing [i][n][j] for fixed n and varying i, we restructure to promote spatial locality.

    for (n = 0; n < len; n++) {
        INTFLOAT temp0_0 = (UINTFLOAT)in[0][n][0];
        INTFLOAT temp1_0 = (UINTFLOAT)in[0][n][1];
        out[0][n][0] = temp0_0 + in[1][n][0] + in[2][n][0] + (UINTFLOAT)in[3][n][0] + in[4][n][0] + in[5][n][0];
        out[1][n][0] = temp1_0 + in[1][n][1] + in[2][n][1] + (UINTFLOAT)in[3][n][1] + in[4][n][1] + in[5][n][1];

        INTFLOAT temp6_0 = (UINTFLOAT)in[6][n][0];
        INTFLOAT temp6_1 = (UINTFLOAT)in[6][n][1];
        out[0][n][1] = temp6_0 + in[7][n][0];
        out[1][n][1] = temp6_1 + in[7][n][1];

        out[0][n][2] = (UINTFLOAT)in[8][n][0] + in[9][n][0];
        out[1][n][2] = (UINTFLOAT)in[8][n][1] + in[9][n][1];
    }
}
