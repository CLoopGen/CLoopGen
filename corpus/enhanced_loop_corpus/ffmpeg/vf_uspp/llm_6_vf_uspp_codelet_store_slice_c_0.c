#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(8)))  uint8_t dither[8][8];
extern uint8_t *dst;
extern  uint16_t *src;
extern int dst_stride;
extern int src_stride;
extern int width;
extern int height;
extern int log2_scale;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    const uint8_t *d = dither[y & 7];
    for (x = 0; x < width; x += 8) {
        int temp0, temp1, temp2, temp3, temp4, temp5, temp6, temp7;

        temp0 = ((src[x + y * src_stride + 0] << log2_scale) + d[0]) >> 8;
        temp1 = ((src[x + y * src_stride + 1] << log2_scale) + d[1]) >> 8;
        temp2 = ((src[x + y * src_stride + 2] << log2_scale) + d[2]) >> 8;
        temp3 = ((src[x + y * src_stride + 3] << log2_scale) + d[3]) >> 8;
        temp4 = ((src[x + y * src_stride + 4] << log2_scale) + d[4]) >> 8;
        temp5 = ((src[x + y * src_stride + 5] << log2_scale) + d[5]) >> 8;
        temp6 = ((src[x + y * src_stride + 6] << log2_scale) + d[6]) >> 8;
        temp7 = ((src[x + y * src_stride + 7] << log2_scale) + d[7]) >> 8;

        if (temp0 & 256) temp0 = ~(temp0 >> 31);
        if (temp1 & 256) temp1 = ~(temp1 >> 31);
        if (temp2 & 256) temp2 = ~(temp2 >> 31);
        if (temp3 & 256) temp3 = ~(temp3 >> 31);
        if (temp4 & 256) temp4 = ~(temp4 >> 31);
        if (temp5 & 256) temp5 = ~(temp5 >> 31);
        if (temp6 & 256) temp6 = ~(temp6 >> 31);
        if (temp7 & 256) temp7 = ~(temp7 >> 31);

        dst[x + y * dst_stride + 0] = temp0;
        dst[x + y * dst_stride + 1] = temp1;
        dst[x + y * dst_stride + 2] = temp2;
        dst[x + y * dst_stride + 3] = temp3;
        dst[x + y * dst_stride + 4] = temp4;
        dst[x + y * dst_stride + 5] = temp5;
        dst[x + y * dst_stride + 6] = temp6;
        dst[x + y * dst_stride + 7] = temp7;
    }
}
}
