#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT in[5][44][2];
extern INTFLOAT L[2][38][64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computations to access 'in' and 'L' in row-major friendly strides
    // We unroll the inner loop by processing multiple elements at once to improve spatial locality
    for (i = 0; i < 5; i++) {
        INTFLOAT *in_base = &in[i][6][0];  // Base pointer for in[i][6][0]
        for (j = 0; j < 38; j++) {
            int idx = j * 2;
            in_base[idx]     = L[0][j][i];  // in[i][j+6][0]
            in_base[idx + 1] = L[1][j][i];  // in[i][j+6][1]
        }
    }
}
