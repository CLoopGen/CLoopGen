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
for (n = 0; n < len; n += 2) {
    if (n + 1 < len) {
        // Unroll loop by factor of 2 to increase computational intensity
        out[0][n][0] = (UINTFLOAT)in[0][n][0] + in[1][n][0] + in[2][n][0] + (UINTFLOAT)in[3][n][0] + in[4][n][0] + in[5][n][0];
        out[1][n][0] = (UINTFLOAT)in[0][n][1] + in[1][n][1] + in[2][n][1] + (UINTFLOAT)in[3][n][1] + in[4][n][1] + in[5][n][1];
        out[0][n][1] = (UINTFLOAT)in[6][n][0] + in[7][n][0];
        out[1][n][1] = (UINTFLOAT)in[6][n][1] + in[7][n][1];
        out[0][n][2] = (UINTFLOAT)in[8][n][0] + in[9][n][0];
        out[1][n][2] = (UINTFLOAT)in[8][n][1] + in[9][n][1];

        out[0][n+1][0] = (UINTFLOAT)in[0][n+1][0] + in[1][n+1][0] + in[2][n+1][0] + (UINTFLOAT)in[3][n+1][0] + in[4][n+1][0] + in[5][n+1][0];
        out[1][n+1][0] = (UINTFLOAT)in[0][n+1][1] + in[1][n+1][1] + in[2][n+1][1] + (UINTFLOAT)in[3][n+1][1] + in[4][n+1][1] + in[5][n+1][1];
        out[0][n+1][1] = (UINTFLOAT)in[6][n+1][0] + in[7][n+1][0];
        out[1][n+1][1] = (UINTFLOAT)in[6][n+1][1] + in[7][n+1][1];
        out[0][n+1][2] = (UINTFLOAT)in[8][n+1][0] + in[9][n+1][0];
        out[1][n+1][2] = (UINTFLOAT)in[8][n+1][1] + in[9][n+1][1];
    } else {
        // Handle remaining element if len is odd
        out[0][n][0] = (UINTFLOAT)in[0][n][0] + in[1][n][0] + in[2][n][0] + (UINTFLOAT)in[3][n][0] + in[4][n][0] + in[5][n][0];
        out[1][n][0] = (UINTFLOAT)in[0][n][1] + in[1][n][1] + in[2][n][1] + (UINTFLOAT)in[3][n][1] + in[4][n][1] + in[5][n][1];
        out[0][n][1] = (UINTFLOAT)in[6][n][0] + in[7][n][0];
        out[1][n][1] = (UINTFLOAT)in[6][n][1] + in[7][n][1];
        out[0][n][2] = (UINTFLOAT)in[8][n][0] + in[9][n][0];
        out[1][n][2] = (UINTFLOAT)in[8][n][1] + in[9][n][1];
    }
}
}
