#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32)))  uint8_t dither[8][8];
extern uint8_t *dst;
extern int16_t *src;
extern ptrdiff_t dst_stride;
extern ptrdiff_t src_stride;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern ptrdiff_t log2_scale;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    const uint8_t *d = dither[y & 7];
    for (x = 0; x < width; x += 4) {
        int temp;
        temp = (src[x + 0] + (d[0] >> log2_scale)) >> (6 - log2_scale);
        src[x + 0] = 0;
        temp = (temp & 256) ? ~(temp >> 31) : temp;
        dst[x + 0] = (uint8_t)temp;
        
        temp = (src[x + 1] + (d[1] >> log2_scale)) >> (6 - log2_scale);
        src[x + 1] = 0;
        temp = (temp & 256) ? ~(temp >> 31) : temp;
        dst[x + 1] = (uint8_t)temp;
        
        temp = (src[x + 2] + (d[2] >> log2_scale)) >> (6 - log2_scale);
        src[x + 2] = 0;
        temp = (temp & 256) ? ~(temp >> 31) : temp;
        dst[x + 2] = (uint8_t)temp;
        
        temp = (src[x + 3] + (d[3] >> log2_scale)) >> (6 - log2_scale);
        src[x + 3] = 0;
        temp = (temp & 256) ? ~(temp >> 31) : temp;
        dst[x + 3] = (uint8_t)temp;
    }
    src += src_stride;
    dst += dst_stride;
}
}
