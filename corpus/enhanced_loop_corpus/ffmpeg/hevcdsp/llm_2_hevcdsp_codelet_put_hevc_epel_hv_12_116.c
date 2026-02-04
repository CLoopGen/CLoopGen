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
    // Variant 1: Consecutive Memory Access Pattern
    // Rewritten to access tmp with consecutive indices by precomputing offset
    int base_offset = -64;
    for (y = 0; y < height; y++) {
        int offset = base_offset + y * 64;
        for (x = 0; x < width; x++) {
            int idx = x;
            dst[idx] = (filter[0] * tmp[offset + idx] +
                        filter[1] * tmp[offset + idx + 64] +
                        filter[2] * tmp[offset + idx + 128] +
                        filter[3] * tmp[offset + idx + 192]) >> 6;
        }
        dst += 64;
    }
}
