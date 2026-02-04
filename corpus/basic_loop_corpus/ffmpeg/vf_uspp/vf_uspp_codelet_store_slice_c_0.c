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
        int temp;
        do {
            temp = ((src[x + y * src_stride + 0] << log2_scale) + d[0]) >> 8;
            if (temp & 256)
                temp = ~(temp >> 31);
            dst[x + y * dst_stride + 0] = temp;
        } while (0);
        do {
            temp = ((src[x + y * src_stride + 1] << log2_scale) + d[1]) >> 8;
            if (temp & 256)
                temp = ~(temp >> 31);
            dst[x + y * dst_stride + 1] = temp;
        } while (0);
        do {
            temp = ((src[x + y * src_stride + 2] << log2_scale) + d[2]) >> 8;
            if (temp & 256)
                temp = ~(temp >> 31);
            dst[x + y * dst_stride + 2] = temp;
        } while (0);
        do {
            temp = ((src[x + y * src_stride + 3] << log2_scale) + d[3]) >> 8;
            if (temp & 256)
                temp = ~(temp >> 31);
            dst[x + y * dst_stride + 3] = temp;
        } while (0);
        do {
            temp = ((src[x + y * src_stride + 4] << log2_scale) + d[4]) >> 8;
            if (temp & 256)
                temp = ~(temp >> 31);
            dst[x + y * dst_stride + 4] = temp;
        } while (0);
        do {
            temp = ((src[x + y * src_stride + 5] << log2_scale) + d[5]) >> 8;
            if (temp & 256)
                temp = ~(temp >> 31);
            dst[x + y * dst_stride + 5] = temp;
        } while (0);
        do {
            temp = ((src[x + y * src_stride + 6] << log2_scale) + d[6]) >> 8;
            if (temp & 256)
                temp = ~(temp >> 31);
            dst[x + y * dst_stride + 6] = temp;
        } while (0);
        do {
            temp = ((src[x + y * src_stride + 7] << log2_scale) + d[7]) >> 8;
            if (temp & 256)
                temp = ~(temp >> 31);
            dst[x + y * dst_stride + 7] = temp;
        } while (0);
    }
}

}
