#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

typedef unsigned int UINTFLOAT;

extern INTFLOAT out[2][38][64];
extern INTFLOAT in[91][32][2];
extern int len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access arrays with a fixed stride across the second dimension to simulate non-unit stride access
    // This variant simulates a scenario where data is accessed with gaps, potentially modeling downsampled or interleaved processing
    const int stride = 2;
    for (n = 0; n < len; n += stride) {
        if (n >= len) break;

        // Use strided access: only process every 'stride'-th element in a grouped fashion
        out[0][n][0] = (UINTFLOAT)in[0][n][0] + in[1][n][0] + in[2][n][0] + (UINTFLOAT)in[3][n][0] + in[4][n][0] + in[5][n][0];
        out[1][n][0] = (UINTFLOAT)in[0][n][1] + in[1][n][1] + in[2][n][1] + (UINTFLOAT)in[3][n][1] + in[4][n][1] + in[5][n][1];

        out[0][n][1] = (UINTFLOAT)in[6][n][0] + in[7][n][0];
        out[1][n][1] = (UINTFLOAT)in[6][n][1] + in[7][n][1];

        out[0][n][2] = (UINTFLOAT)in[8][n][0] + in[9][n][0];
        out[1][n][2] = (UINTFLOAT)in[8][n][1] + in[9][n][1];

        // Handle next element in stride if within bounds
        int n_next = n + 1;
        if (n_next < len) {
            out[0][n_next][0] = (UINTFLOAT)in[0][n_next][0] + in[1][n_next][0] + in[2][n_next][0] + (UINTFLOAT)in[3][n_next][0] + in[4][n_next][0] + in[5][n_next][0];
            out[1][n_next][0] = (UINTFLOAT)in[0][n_next][1] + in[1][n_next][1] + in[2][n_next][1] + (UINTFLOAT)in[3][n_next][1] + in[4][n_next][1] + in[5][n_next][1];

            out[0][n_next][1] = (UINTFLOAT)in[6][n_next][0] + in[7][n_next][0];
            out[1][n_next][1] = (UINTFLOAT)in[6][n_next][1] + in[7][n_next][1];

            out[0][n_next][2] = (UINTFLOAT)in[8][n_next][0] + in[9][n_next][0];
            out[1][n_next][2] = (UINTFLOAT)in[8][n_next][1] + in[9][n_next][1];
        }
    }
}
