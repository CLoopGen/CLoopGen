#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing in[0][i] and in[1][i] consecutively, access with a fixed stride (e.g., every 2nd element)
    // This changes spatial locality and may affect cache behavior.
    int stride = 2;
    int j;
    for (j = 0; j < len; j += stride) {
        unsigned int a = in[0][j];
        unsigned int b = in[1][j];
        (*samples++) = a << shift;
        (*samples++) = (a - b) << shift;
        // Handle potential odd-length edge case by checking bounds
        if (j + 1 < len) {
            unsigned int a_next = in[0][j + 1];
            unsigned int b_next = in[1][j + 1];
            (*samples++) = a_next << shift;
            (*samples++) = (a_next - b_next) << shift;
        }
    }
}
