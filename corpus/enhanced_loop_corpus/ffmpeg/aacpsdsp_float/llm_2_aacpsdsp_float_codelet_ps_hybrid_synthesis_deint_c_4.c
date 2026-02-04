#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT out[2][38][64];
extern INTFLOAT (*in)[32][2];
extern int i;
extern int len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder loop to access memory sequentially in the innermost loop by swapping loop order.
    // This improves spatial locality by accessing `in[i][n][k]` and `out[k][n][i]` with stride-1 access when possible.
    for (int k = 0; k < 2; k++) {
        for (n = 0; n < len; n++) {
            for (i = 0; i < 64; i++) {
                out[k][n][i] = in[i][n][k];
            }
        }
    }
}
