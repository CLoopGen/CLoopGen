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
    const uint8_t *d = dither[y % 8];
    for (x = 0; x < width; x += 8) {
        int temp0, temp1, temp2, temp3, temp4, temp5, temp6, temp7;
        int16_t s0 = src[x + y * src_linesize + 0];
        int16_t s1 = src[x + y * src_linesize + 1];
        int16_t s2 = src[x + y * src_linesize + 2];
        int16_t s3 = src[x + y * src_linesize + 3];
        int16_t s4 = src[x + y * src_linesize + 4];
        int16_t s5 = src[x + y * src_linesize + 5];
        int16_t s6 = src[x + y * src_linesize + 6];
        int16_t s7 = src[x + y * src_linesize + 7];

        temp0 = ((s0 << log2_scale) + d[0]) >> 6;
        temp1 = ((s1 << log2_scale) + d[1]) >> 6;
        temp2 = ((s2 << log2_scale) + d[2]) >> 6;
        temp3 = ((s3 << log2_scale) + d[3]) >> 6;
        temp4 = ((s4 << log2_scale) + d[4]) >> 6;
        temp5 = ((s5 << log2_scale) + d[5]) >> 6;
        temp6 = ((s6 << log2_scale) + d[6]) >> 6;
        temp7 = ((s7 << log2_scale) + d[7]) >> 6;

        if (temp0 & 256) temp0 = ~(temp0 >> 31);
        if (temp1 & 256) temp1 = ~(temp1 >> 31);
        if (temp2 & 256) temp2 = ~(temp2 >> 31);
        if (temp3 & 256) temp3 = ~(temp3 >> 31);
        if (temp4 & 256) temp4 = ~(temp4 >> 31);
        if (temp5 & 256) temp5 = ~(temp5 >> 31);
        if (temp6 & 256) temp6 = ~(temp6 >> 31);
        if (temp7 & 256) temp7 = ~(temp7 >> 31);

        dst[x + y * dst_linesize + 0] = temp0;
        dst[x + y * dst_linesize + 1] = temp1;
        dst[x + y * dst_linesize + 2] = temp2;
        dst[x + y * dst_linesize + 3] = temp3;
        dst[x + y * dst_linesize + 4] = temp4;
        dst[x + y * dst_linesize + 5] = temp5;
        dst[x + y * dst_linesize + 6] = temp6;
        dst[x + y * dst_linesize + 7] = temp7;
    }
}
}
