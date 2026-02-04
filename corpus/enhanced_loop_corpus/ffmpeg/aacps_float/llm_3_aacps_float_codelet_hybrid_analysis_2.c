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
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic to simulate non-contiguous access
    // This variant uses a fixed offset stride pattern, simulating cache-unfriendly but realistic DSP-style access
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 38; j++) {
            // Use explicit pointer arithmetic to create strided access pattern
            INTFLOAT *in_ptr0 = &in[i][(j << 1) + 6][0];  // Artificially double-stride the row index
            INTFLOAT *in_ptr1 = &in[i][(j << 1) + 6][1];
            // Access L with normal indices but alternate order to break sequentiality
            if ((j << 1) + 6 < 44) {  // Bound check due to striding
                *in_ptr0 = L[0][j][i];
                *in_ptr1 = L[1][j][i];
            }
        }
    }
}
