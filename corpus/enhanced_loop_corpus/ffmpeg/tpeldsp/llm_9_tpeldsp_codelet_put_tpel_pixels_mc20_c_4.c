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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        if (i < height) {
            dst[j] = ((src[j] + 2 * src[j + 1] + 1) * 683) >> 11;
        }
        if (i + 1 < height) {
            uint8_t* src_next = src + stride;
            uint8_t* dst_next = dst + stride;
            dst_next[j] = ((src_next[j] + 2 * src_next[j + 1] + 1) * 683) >> 11;
        }
    }
    src += 2 * stride;
    dst += 2 * stride;
}
}
