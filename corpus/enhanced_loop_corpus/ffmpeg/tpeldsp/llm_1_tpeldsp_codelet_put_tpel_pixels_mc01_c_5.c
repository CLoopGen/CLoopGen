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
    if (col == 0) {
        uint8_t *src_row = src + row * stride;
        uint8_t *dst_row = dst + row * stride;
    }
    dst[col] = ((2 * src[col] + src[col + stride] + 1) * 683) >> 11;
    if (col == width - 1) {
        src += stride;
        dst += stride;
    }
}
}
