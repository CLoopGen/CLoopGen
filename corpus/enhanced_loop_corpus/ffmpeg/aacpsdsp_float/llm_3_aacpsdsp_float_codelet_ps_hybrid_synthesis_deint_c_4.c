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
    // Variant 2: Strided Memory Access Pattern with Pointer Arithmetic
    // Use pointer arithmetic to access arrays with explicit strides, simulating a non-unit stride access pattern.
    // We maintain original loop nesting but express accesses via calculated offsets.
    INTFLOAT *out0_base = &out[0][0][0];
    INTFLOAT *out1_base = &out[1][0][0];
    for (i = 0; i < 64; i++) {
        for (n = 0; n < len; n++) {
            // Compute strided offsets: out[0][n][i], out[1][n][i], in[i][n][0], in[i][n][1]
            int out_offset = n * 64 + i;
            int in_offset = i * 32 * 2 + n * 2;
            out0_base[out_offset] = in[0][0][0] + in_offset;
            out1_base[out_offset] = in[0][0][1] + in_offset;
        }
    }
}
