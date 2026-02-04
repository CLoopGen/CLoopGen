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



void loop() {
    for (y = 0; y < height; y++) {
        const uint8_t *d = dither[y & 7];
        uint16_t *src_row = src + y * src_stride;
        uint8_t *dst_row = dst + y * dst_stride;
        for (x = 0; x < width; x += 8) {
            int temp0 = ((src_row[x + 0] << log2_scale) + d[0]) >> 8;
            int temp1 = ((src_row[x + 1] << log2_scale) + d[1]) >> 8;
            int temp2 = ((src_row[x + 2] << log2_scale) + d[2]) >> 8;
            int temp3 = ((src_row[x + 3] << log2_scale) + d[3]) >> 8;
            int temp4 = ((src_row[x + 4] << log2_scale) + d[4]) >> 8;
            int temp5 = ((src_row[x + 5] << log2_scale) + d[5]) >> 8;
            int temp6 = ((src_row[x + 6] << log2_scale) + d[6]) >> 8;
            int temp7 = ((src_row[x + 7] << log2_scale) + d[7]) >> 8;

            temp0 = (temp0 & 256) ? ~(temp0 >> 31) : temp0;
            temp1 = (temp1 & 256) ? ~(temp1 >> 31) : temp1;
            temp2 = (temp2 & 256) ? ~(temp2 >> 31) : temp2;
            temp3 = (temp3 & 256) ? ~(temp3 >> 31) : temp3;
            temp4 = (temp4 & 256) ? ~(temp4 >> 31) : temp4;
            temp5 = (temp5 & 256) ? ~(temp5 >> 31) : temp5;
            temp6 = (temp6 & 256) ? ~(temp6 >> 31) : temp6;
            temp7 = (temp7 & 256) ? ~(temp7 >> 31) : temp7;

            dst_row[x + 0] = temp0;
            dst_row[x + 1] = temp1;
            dst_row[x + 2] = temp2;
            dst_row[x + 3] = temp3;
            dst_row[x + 4] = temp4;
            dst_row[x + 5] = temp5;
            dst_row[x + 6] = temp6;
            dst_row[x + 7] = temp7;
        }
    }
}
