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
for (y = 0; y < height; y += 2) {
    const uint8_t *d1 = dither[y % 8];
    const uint8_t *d2 = dither[(y + 1) % 8];
    for (x = 0; x < width; x += 8) {
        int temp;
        // First row processing
        temp = (src[x + 0] + (d1[0] >> log2_scale)) >> (6 - log2_scale);
        if (temp & 256) temp = ~(temp >> 31);
        dst[x + 0] = temp;
        src[x + 0] = 0;

        temp = (src[x + 1] + (d1[1] >> log2_scale)) >> (6 - log2_scale);
        if (temp & 256) temp = ~(temp >> 31);
        dst[x + 1] = temp;
        src[x + 1] = 0;

        temp = (src[x + 2] + (d1[2] >> log2_scale)) >> (6 - log2_scale);
        if (temp & 256) temp = ~(temp >> 31);
        dst[x + 2] = temp;
        src[x + 2] = 0;

        temp = (src[x + 3] + (d1[3] >> log2_scale)) >> (6 - log2_scale);
        if (temp & 256) temp = ~(temp >> 31);
        dst[x + 3] = temp;
        src[x + 3] = 0;

        temp = (src[x + 4] + (d1[4] >> log2_scale)) >> (6 - log2_scale);
        if (temp & 256) temp = ~(temp >> 31);
        dst[x + 4] = temp;
        src[x + 4] = 0;

        temp = (src[x + 5] + (d1[5] >> log2_scale)) >> (6 - log2_scale);
        if (temp & 256) temp = ~(temp >> 31);
        dst[x + 5] = temp;
        src[x + 5] = 0;

        temp = (src[x + 6] + (d1[6] >> log2_scale)) >> (6 - log2_scale);
        if (temp & 256) temp = ~(temp >> 31);
        dst[x + 6] = temp;
        src[x + 6] = 0;

        temp = (src[x + 7] + (d1[7] >> log2_scale)) >> (6 - log2_scale);
        if (temp & 256) temp = ~(temp >> 31);
        dst[x + 7] = temp;
        src[x + 7] = 0;

        // Second row (if within bounds)
        if (y + 1 < height) {
            int16_t *src_next = src + src_stride;
            uint8_t *dst_next = dst + dst_stride;
            temp = (src_next[x + 0] + (d2[0] >> log2_scale)) >> (6 - log2_scale);
            if (temp & 256) temp = ~(temp >> 31);
            dst_next[x + 0] = temp;
            src_next[x + 0] = 0;

            temp = (src_next[x + 1] + (d2[1] >> log2_scale)) >> (6 - log2_scale);
            if (temp & 256) temp = ~(temp >> 31);
            dst_next[x + 1] = temp;
            src_next[x + 1] = 0;

            temp = (src_next[x + 2] + (d2[2] >> log2_scale)) >> (6 - log2_scale);
            if (temp & 256) temp = ~(temp >> 31);
            dst_next[x + 2] = temp;
            src_next[x + 2] = 0;

            temp = (src_next[x + 3] + (d2[3] >> log2_scale)) >> (6 - log2_scale);
            if (temp & 256) temp = ~(temp >> 31);
            dst_next[x + 3] = temp;
            src_next[x + 3] = 0;

            temp = (src_next[x + 4] + (d2[4] >> log2_scale)) >> (6 - log2_scale);
            if (temp & 256) temp = ~(temp >> 31);
            dst_next[x + 4] = temp;
            src_next[x + 4] = 0;

            temp = (src_next[x + 5] + (d2[5] >> log2_scale)) >> (6 - log2_scale);
            if (temp & 256) temp = ~(temp >> 31);
            dst_next[x + 5] = temp;
            src_next[x + 5] = 0;

            temp = (src_next[x + 6] + (d2[6] >> log2_scale)) >> (6 - log2_scale);
            if (temp & 256) temp = ~(temp >> 31);
            dst_next[x + 6] = temp;
            src_next[x + 6] = 0;

            temp = (src_next[x + 7] + (d2[7] >> log2_scale)) >> (6 - log2_scale);
            if (temp & 256) temp = ~(temp >> 31);
            dst_next[x + 7] = temp;
            src_next[x + 7] = 0;
        }
    }
    src += 2 * src_stride;
    dst += 2 * dst_stride;
}
}
