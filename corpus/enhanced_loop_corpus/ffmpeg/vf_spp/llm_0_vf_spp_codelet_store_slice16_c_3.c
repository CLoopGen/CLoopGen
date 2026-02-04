#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  int16_t *src;
extern int dst_linesize;
extern int src_linesize;
extern int width;
extern int height;
extern int log2_scale;
extern  uint8_t dither[8][8];
extern int y;
extern int x;
extern unsigned int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    const uint8_t *d = dither[y];
    for (x = 0; x < width; x += 8) {
        int temp;
        temp = ((src[x + y * src_linesize + 0] << log2_scale) + (d[0] >> 1)) >> 5;
        if (temp & mask)
            temp = ~(temp >> 31);
        dst[x + y * dst_linesize + 0] = temp;

        temp = ((src[x + y * src_linesize + 1] << log2_scale) + (d[1] >> 1)) >> 5;
        if (temp & mask)
            temp = ~(temp >> 31);
        dst[x + y * dst_linesize + 1] = temp;

        temp = ((src[x + y * src_linesize + 2] << log2_scale) + (d[2] >> 1)) >> 5;
        if (temp & mask)
            temp = ~(temp >> 31);
        dst[x + y * dst_linesize + 2] = temp;

        temp = ((src[x + y * src_linesize + 3] << log2_scale) + (d[3] >> 1)) >> 5;
        if (temp & mask)
            temp = ~(temp >> 31);
        dst[x + y * dst_linesize + 3] = temp;

        temp = ((src[x + y * src_linesize + 4] << log2_scale) + (d[4] >> 1)) >> 5;
        if (temp & mask)
            temp = ~(temp >> 31);
        dst[x + y * dst_linesize + 4] = temp;

        temp = ((src[x + y * src_linesize + 5] << log2_scale) + (d[5] >> 1)) >> 5;
        if (temp & mask)
            temp = ~(temp >> 31);
        dst[x + y * dst_linesize + 5] = temp;

        temp = ((src[x + y * src_linesize + 6] << log2_scale) + (d[6] >> 1)) >> 5;
        if (temp & mask)
            temp = ~(temp >> 31);
        dst[x + y * dst_linesize + 6] = temp;

        temp = ((src[x + y * src_linesize + 7] << log2_scale) + (d[7] >> 1)) >> 5;
        if (temp & mask)
            temp = ~(temp >> 31);
        dst[x + y * dst_linesize + 7] = temp;
    }
}
}
