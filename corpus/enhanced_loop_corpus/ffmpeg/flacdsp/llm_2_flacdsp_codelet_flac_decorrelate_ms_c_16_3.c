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
    // Instead of accessing elements sequentially (i), access them with a stride of 2
    // and handle remaining elements in a second pass to maintain correctness.
    int stride = 2;
    int remainder = len % stride;

    // First, process strided elements: i = 0, 2, 4, ..., up to largest even < len
    for (i = 0; i < len - remainder; i += stride) {
        unsigned int a = in[0][i];
        int b = in[1][i];
        a -= b >> 1;
        (*samples++) = (a + b) << shift;
        (*samples++) = a << shift;
    }

    // Then, handle the last 'remainder' elements (if any, i.e., when len is odd)
    for (i = len - remainder; i < len; i++) {
        unsigned int a = in[0][i];
        int b = in[1][i];
        a -= b >> 1;
        (*samples++) = (a + b) << shift;
        (*samples++) = a << shift;
    }
}
