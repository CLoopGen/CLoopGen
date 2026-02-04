#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **samples;
extern int16_t **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern int64_t v0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing matrix[0][j] consecutively, we access it with a fixed stride (e.g., every 2nd element, wrapping appropriately)
    // To maintain correctness, we adjust indexing with modulo to stay within bounds.
    for (i = 0; i < len; i++) {
        v0 = 0;
        int stride = 2;
        for (j = 0; j < in_ch; j++) {
            int idx = (j * stride) % in_ch; // strided access into matrix
            v0 += (int64_t)samples[j][i] * matrix[0][idx];
        }
        samples[0][i] = (v0 + 2048) >> 12;
    }
}
