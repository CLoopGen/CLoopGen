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
    for (x = 0; x < width; x++) {
        int temp;
        const uint8_t *d = dither[y & 7];
        switch (x & 7) {
            case 0:
                temp = ((src[x + y * src_linesize] << log2_scale) + d[0]) >> 6;
                if (temp & 256)
                    temp = ~(temp >> 31);
                dst[x + y * dst_linesize] = temp;
                break;
            case 1:
                temp = ((src[x + y * src_linesize] << log2_scale) + d[1]) >> 6;
                if (temp & 256)
                    temp = ~(temp >> 31);
                dst[x + y * dst_linesize] = temp;
                break;
            case 2:
                temp = ((src[x + y * src_linesize] << log2_scale) + d[2]) >> 6;
                if (temp & 256)
                    temp = ~(temp >> 31);
                dst[x + y * dst_linesize] = temp;
                break;
            case 3:
                temp = ((src[x + y * src_linesize] << log2_scale) + d[3]) >> 6;
                if (temp & 256)
                    temp = ~(temp >> 31);
                dst[x + y * dst_linesize] = temp;
                break;
            case 4:
                temp = ((src[x + y * src_linesize] << log2_scale) + d[4]) >> 6;
                if (temp & 256)
                    temp = ~(temp >> 31);
                dst[x + y * dst_linesize] = temp;
                break;
            case 5:
                temp = ((src[x + y * src_linesize] << log2_scale) + d[5]) >> 6;
                if (temp & 256)
                    temp = ~(temp >> 31);
                dst[x + y * dst_linesize] = temp;
                break;
            case 6:
                temp = ((src[x + y * src_linesize] << log2_scale) + d[6]) >> 6;
                if (temp & 256)
                    temp = ~(temp >> 31);
                dst[x + y * dst_linesize] = temp;
                break;
            case 7:
                temp = ((src[x + y * src_linesize] << log2_scale) + d[7]) >> 6;
                if (temp & 256)
                    temp = ~(temp >> 31);
                dst[x + y * dst_linesize] = temp;
                break;
        }
    }
}
}
