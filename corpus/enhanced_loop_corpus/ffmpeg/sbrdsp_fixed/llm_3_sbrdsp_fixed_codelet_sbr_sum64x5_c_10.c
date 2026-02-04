#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Increased Stride (Reverse Order)
    // Change access pattern to a higher stride and reverse the order of indexing
    // to create temporal and spatial memory access variation.
    // Now we access elements at k, k+1, k+2, ..., but from different segments.
    for (k = 0; k < 64; k++) {
        INTFLOAT idx0 = k;
        INTFLOAT idx1 = 63 - k + 64;      // Reverse index in second block
        INTFLOAT idx2 = k + 128;          // Forward in third block
        INTFLOAT idx3 = 191 - k + 192;    // Reverse in fourth block
        INTFLOAT idx4 = k + 256;          // Forward in fifth block
        INTFLOAT f = z[idx0] + z[idx1] + z[idx2] + z[idx3] + z[idx4];
        z[k] = f;
    }
}
