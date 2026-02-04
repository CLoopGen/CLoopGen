#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT out[2][38][64];
extern INTFLOAT (*in)[32][2];
extern int i;
extern int len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder loops to access memory consecutively by swapping the outer and inner loop indices
    // This improves spatial locality by accessing `in[i][n][*]` in increasing order of `i`
    for (int n_local = 0; n_local < len; n_local++) {
        for (int i_local = 0; i_local < 64; i_local++) {
            out[0][n_local][i_local] = in[i_local][n_local][0];
            out[1][n_local][i_local] = in[i_local][n_local][1];
        }
    }
}
