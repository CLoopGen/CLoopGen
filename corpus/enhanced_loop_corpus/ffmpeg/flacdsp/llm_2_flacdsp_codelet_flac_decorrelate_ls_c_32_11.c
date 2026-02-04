#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int32_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride for input arrays
    // Instead of accessing in[0][i] and in[1][i], we now access every 2nd element
    // This changes spatial locality and may affect cache behavior
    int stride = 2;
    int n = len / stride;  // Adjust effective length due to striding
    for (i = 0; i < n; i++) {
        unsigned int a = in[0][i * stride];
        unsigned int b = in[1][i * stride];
        (*samples++) = a << shift;
        (*samples++) = (a - b) << shift;
    }
}
