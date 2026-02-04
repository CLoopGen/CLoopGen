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
extern int64_t v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing matrix[0][j] and matrix[1][j] in inner loop, use a fixed stride access
    // assuming matrix is stored row-major and we precompute offsets for better predictability
    int64_t *mat0 = (int64_t*)matrix[0]; // Promote to 64-bit for consistent arithmetic
    int64_t *mat1 = (int64_t*)matrix[1];
    for (i = 0; i < len; i++) {
        v0 = v1 = 0;
        for (j = 0; j < in_ch; j += 2) {
            // Process two elements per iteration with strided access
            if (j + 1 < in_ch) {
                v0 += (int64_t)samples[j][i] * mat0[j] + (int64_t)samples[j+1][i] * mat0[j+1];
                v1 += (int64_t)samples[j][i] * mat1[j] + (int64_t)samples[j+1][i] * mat1[j+1];
            } else {
                v0 += (int64_t)samples[j][i] * mat0[j];
                v1 += (int64_t)samples[j][i] * mat1[j];
            }
        }
        samples[0][i] = (v0 + 2048) >> 12;
        samples[1][i] = (v1 + 2048) >> 12;
    }
}
