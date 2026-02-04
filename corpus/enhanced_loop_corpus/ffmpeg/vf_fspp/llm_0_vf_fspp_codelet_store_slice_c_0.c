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
    const uint8_t *d = dither[y];
    for (x = 0; x < width; x += 4) {
        int temp;
        temp = (src[x + 0] + (d[0] >> log2_scale)) >> (6 - log2_scale);
        src[x + 0] = src[x + 0 - 8 * src_stride] = 0;
        if (temp & 256)
            temp = ~(temp >> 31);
        dst[x + 0] = temp;

        temp = (src[x + 1] + (d[1] >> log2_scale)) >> (6 - log2_scale);
        src[x + 1] = src[x + 1 - 8 * src_stride] = 0;
        if (temp & 256)
            temp = ~(temp >> 31);
        dst[x + 1] = temp;

        temp = (src[x + 2] + (d[2] >> log2_scale)) >> (6 - log2_scale);
        src[x + 2] = src[x + 2 - 8 * src_stride] = 0;
        if (temp & 256)
            temp = ~(temp >> 31);
        dst[x + 2] = temp;

        temp = (src[x + 3] + (d[3] >> log2_scale)) >> (6 - log2_scale);
        src[x + 3] = src[x + 3 - 8 * src_stride] = 0;
        if (temp & 256)
            temp = ~(temp >> 31);
        dst[x + 3] = temp;
    }
    for (; x < width; x++) {
        int temp;
        temp = (src[x] + (d[x & 7] >> log2_scale)) >> (6 - log2_scale);
        src[x] = src[x - 8 * src_stride] = 0;
        if (temp & 256)
            temp = ~(temp >> 31);
        dst[x] = temp;
    }
    src += src_stride;
    dst += dst_stride;
}
}
