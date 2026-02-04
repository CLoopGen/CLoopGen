#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  int16_t *src;
extern int dst_linesize;
extern int src_linesize;
extern int width;
extern int height;
extern int log2_scale;
extern  uint8_t dither[8][8];
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    const uint8_t *d = dither[y];
    for (x = 0; x < width; x += 8) {
        int temp;
        temp = ((src[x + y * src_linesize + 0] << log2_scale) + d[0]) >> 6;
        if (!(temp & 256)) dst[x + y * dst_linesize + 0] = temp;
        else dst[x + y * dst_linesize + 0] = ~(temp >> 31);

        temp = ((src[x + y * src_linesize + 1] << log2_scale) + d[1]) >> 6;
        if (!(temp & 256)) dst[x + y * dst_linesize + 1] = temp;
        else dst[x + y * dst_linesize + 1] = ~(temp >> 31);

        temp = ((src[x + y * src_linesize + 2] << log2_scale) + d[2]) >> 6;
        if (!(temp & 256)) dst[x + y * dst_linesize + 2] = temp;
        else dst[x + y * dst_linesize + 2] = ~(temp >> 31);

        temp = ((src[x + y * src_linesize + 3] << log2_scale) + d[3]) >> 6;
        if (!(temp & 256)) dst[x + y * dst_linesize + 3] = temp;
        else dst[x + y * dst_linesize + 3] = ~(temp >> 31);

        temp = ((src[x + y * src_linesize + 4] << log2_scale) + d[4]) >> 6;
        if (!(temp & 256)) dst[x + y * dst_linesize + 4] = temp;
        else dst[x + y * dst_linesize + 4] = ~(temp >> 31);

        temp = ((src[x + y * src_linesize + 5] << log2_scale) + d[5]) >> 6;
        if (!(temp & 256)) dst[x + y * dst_linesize + 5] = temp;
        else dst[x + y * dst_linesize + 5] = ~(temp >> 31);

        temp = ((src[x + y * src_linesize + 6] << log2_scale) + d[6]) >> 6;
        if (!(temp & 256)) dst[x + y * dst_linesize + 6] = temp;
        else dst[x + y * dst_linesize + 6] = ~(temp >> 31);

        temp = ((src[x + y * src_linesize + 7] << log2_scale) + d[7]) >> 6;
        if (!(temp & 256)) dst[x + y * dst_linesize + 7] = temp;
        else dst[x + y * dst_linesize + 7] = ~(temp >> 31);
    }
}
}
