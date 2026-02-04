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
    // Instead of accessing in[0][i] and in[1][i] with unit stride, use a fixed stride of 2
    // This changes access pattern to skip every other element, simulating strided access
    int stride = 2;
    int n = len / stride;  // Adjust effective length due to striding
    for (i = 0; i < n; i++) {
        unsigned int a = in[0][i * stride];
        unsigned int b = in[1][i * stride];
        (*samples++) = a << shift;
        (*samples++) = (a - b) << shift;
    }
}
