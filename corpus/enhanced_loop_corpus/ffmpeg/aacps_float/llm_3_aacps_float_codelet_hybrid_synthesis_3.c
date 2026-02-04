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
    // Variant 2: Strided Memory Access Pattern
    // Introduce a strided access pattern by processing multiple iterations at once with step size > 1,
    // and group operations to simulate stride-based traversal. Here, we use a fixed unrolled structure
    // with manual indexing to create non-unit strides in memory access for potential vectorization or cache effects.

    int stride = 2;
    int remainder = len % stride;
    int limit = len - remainder;

    // Main loop with stride-2 access
    for (n = 0; n < limit; n += stride) {
        // Process two elements per iteration using strided access
        for (int s = 0; s < stride; s++) {
            int idx = n + s;
            out[0][idx][0] = (UINTFLOAT)in[0][idx][0] + in[1][idx][0] + in[2][idx][0] +
                             (UINTFLOAT)in[3][idx][0] + in[4][idx][0] + in[5][idx][0];
            out[1][idx][0] = (UINTFLOAT)in[0][idx][1] + in[1][idx][1] + in[2][idx][1] +
                             (UINTFLOAT)in[3][idx][1] + in[4][idx][1] + in[5][idx][1];

            out[0][idx][1] = (UINTFLOAT)in[6][idx][0] + in[7][idx][0];
            out[1][idx][1] = (UINTFLOAT)in[6][idx][1] + in[7][idx][1];

            out[0][idx][2] = (UINTFLOAT)in[8][idx][0] + in[9][idx][0];
            out[1][idx][2] = (UINTFLOAT)in[8][idx][1] + in[9][idx][1];
        }
    }

    // Handle remaining elements
    for (; n < len; n++) {
        out[0][n][0] = (UINTFLOAT)in[0][n][0] + in[1][n][0] + in[2][n][0] + (UINTFLOAT)in[3][n][0] + in[4][n][0] + in[5][n][0];
        out[1][n][0] = (UINTFLOAT)in[0][n][1] + in[1][n][1] + in[2][n][1] + (UINTFLOAT)in[3][n][1] + in[4][n][1] + in[5][n][1];
        out[0][n][1] = (UINTFLOAT)in[6][n][0] + in[7][n][0];
        out[1][n][1] = (UINTFLOAT)in[6][n][1] + in[7][n][1];
        out[0][n][2] = (UINTFLOAT)in[8][n][0] + in[9][n][0];
        out[1][n][2] = (UINTFLOAT)in[8][n][1] + in[9][n][1];
    }
}
