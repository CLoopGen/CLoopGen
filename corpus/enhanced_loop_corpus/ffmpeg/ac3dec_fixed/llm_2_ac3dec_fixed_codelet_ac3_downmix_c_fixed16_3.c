#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t **samples;
extern int16_t **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern int v0;
extern int v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing samples[j][i] and matrix[row][j] in natural order,
    // we access matrix with a fixed stride pattern (e.g., reverse column order)
    // to modify memory access locality.

    for (i = 0; i < len; i++) {
        v0 = v1 = 0;
        for (j = 0; j < in_ch; j++) {
            int rev_j = in_ch - 1 - j;  // Reverse the access order of j
            v0 += samples[rev_j][i] * matrix[0][rev_j];
            v1 += samples[rev_j][i] * matrix[1][rev_j];
        }
        samples[0][i] = (v0 + 2048) >> 12;
        samples[1][i] = (v1 + 2048) >> 12;
    }
}
