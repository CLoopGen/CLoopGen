#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Transposed Indexing
    // Access pattern now strides through filter and uses linear index calculation for tmp
    int stride = 64;
    for (y = 0; y < height; y++) {
        int base_idx = y * stride;
        for (x = 0; x < width; x++) {
            int acc = 0;
            // Use a fixed stride of 64 between taps in tmp
            for (int k = 0; k < 4; k++) {
                acc += filter[k] * tmp[base_idx + x + k * 64];
            }
            dst[x] = acc >> 6;
        }
        tmp += 64;
        dst += 64;
    }
}
