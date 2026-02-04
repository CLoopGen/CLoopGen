#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height * width; i++) {
    int row = i / width;
    int col = i % width;
    int src_offset = row * stride;
    dst[col] = ((3 * src[src_offset + col] + 2 * src[src_offset + col + 1] + 
                 4 * src[src_offset + col + stride] + 3 * src[src_offset + col + stride + 1] + 6) * 2731) >> 15;
    if (col == width - 1) {
        src += stride;
        dst += stride;
    }
}
}
