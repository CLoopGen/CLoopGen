#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int h;
extern  uint8_t *cm;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < h; j++) {
    uint8_t *src_base = src;
    uint8_t *dst_base = dst;
    for (i = 0; i < w; i++) {
        int offset = i;
        uint8_t *s = src_base;
        dst_base[offset] = cm[(
            s[-srcStride + offset - 1] - 
            12 * s[-srcStride + offset + 1] - 
            6 * s[-srcStride + offset] + 
            s[-srcStride + offset + 2] +
            -12 * s[offset - 1] + 
            144 * s[offset + 1] + 
            72 * s[offset] - 
            12 * s[offset + 2] +
            -6 * s[srcStride + offset - 1] + 
            72 * s[srcStride + offset + 1] + 
            36 * s[srcStride + offset] - 
            6 * s[srcStride + offset + 2] +
            s[2*srcStride + offset - 1] - 
            12 * s[2*srcStride + offset + 1] - 
            6 * s[2*srcStride + offset] + 
            s[2*srcStride + offset + 2] + 128) >> 8];
    }
    src += srcStride;
    dst += dstStride;
}
}
