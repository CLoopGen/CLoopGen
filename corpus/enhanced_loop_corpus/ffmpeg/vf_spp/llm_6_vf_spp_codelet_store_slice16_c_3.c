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
        int temp0, temp1, temp2, temp3, temp4, temp5, temp6, temp7;

        temp0 = ((src[x + y * src_linesize + 0] << log2_scale) + (d[0] >> 1)) >> 5;
        temp1 = ((src[x + y * src_linesize + 1] << log2_scale) + (d[1] >> 1)) >> 5;
        temp2 = ((src[x + y * src_linesize + 2] << log2_scale) + (d[2] >> 1)) >> 5;
        temp3 = ((src[x + y * src_linesize + 3] << log2_scale) + (d[3] >> 1)) >> 5;
        temp4 = ((src[x + y * src_linesize + 4] << log2_scale) + (d[4] >> 1)) >> 5;
        temp5 = ((src[x + y * src_linesize + 5] << log2_scale) + (d[5] >> 1)) >> 5;
        temp6 = ((src[x + y * src_linesize + 6] << log2_scale) + (d[6] >> 1)) >> 5;
        temp7 = ((src[x + y * src_linesize + 7] << log2_scale) + (d[7] >> 1)) >> 5;

        if (temp0 & mask) temp0 = ~(temp0 >> 31);
        if (temp1 & mask) temp1 = ~(temp1 >> 31);
        if (temp2 & mask) temp2 = ~(temp2 >> 31);
        if (temp3 & mask) temp3 = ~(temp3 >> 31);
        if (temp4 & mask) temp4 = ~(temp4 >> 31);
        if (temp5 & mask) temp5 = ~(temp5 >> 31);
        if (temp6 & mask) temp6 = ~(temp6 >> 31);
        if (temp7 & mask) temp7 = ~(temp7 >> 31);

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
