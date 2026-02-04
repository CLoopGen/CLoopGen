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
    for (x = 0; x < width; x++) {
        int temp = ((src[x + y * src_linesize] << log2_scale) + d[x % 8]) >> 6;
        if (temp & 256)
            temp = ~(temp >> 31);
        dst[x + y * dst_linesize] = temp;
    }
}
}
