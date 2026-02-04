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
        int temp0 = ((src[x + y * src_stride + 0] << log2_scale) + d[0]) >> 8;
        int temp1 = ((src[x + y * src_stride + 1] << log2_scale) + d[1]) >> 8;
        int temp2 = ((src[x + y * src_stride + 2] << log2_scale) + d[2]) >> 8;
        int temp3 = ((src[x + y * src_stride + 3] << log2_scale) + d[3]) >> 8;
        int temp4 = ((src[x + y * src_stride + 4] << log2_scale) + d[4]) >> 8;
        int temp5 = ((src[x + y * src_stride + 5] << log2_scale) + d[5]) >> 8;
        int temp6 = ((src[x + y * src_stride + 6] << log2_scale) + d[6]) >> 8;
        int temp7 = ((src[x + y * src_stride + 7] << log2_scale) + d[7]) >> 8;

        dst[x + y * dst_stride + 0] = (temp0 & 256) ? ~(temp0 >> 31) : temp0;
        dst[x + y * dst_stride + 1] = (temp1 & 256) ? ~(temp1 >> 31) : temp1;
        dst[x + y * dst_stride + 2] = (temp2 & 256) ? ~(temp2 >> 31) : temp2;
        dst[x + y * dst_stride + 3] = (temp3 & 256) ? ~(temp3 >> 31) : temp3;
        dst[x + y * dst_stride + 4] = (temp4 & 256) ? ~(temp4 >> 31) : temp4;
        dst[x + y * dst_stride + 5] = (temp5 & 256) ? ~(temp5 >> 31) : temp5;
        dst[x + y * dst_stride + 6] = (temp6 & 256) ? ~(temp6 >> 31) : temp6;
        dst[x + y * dst_stride + 7] = (temp7 & 256) ? ~(temp7 >> 31) : temp7;
    }
}
}
