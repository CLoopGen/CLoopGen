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
    x = 0;
    while (x < width) {
        for (int offset = 0; offset < 8 && (x + offset) < width; offset++) {
            int temp = ((src[x + offset + y * src_linesize] << log2_scale) + (d[offset] >> 1)) >> 5;
            if (temp & mask)
                temp = ~(temp >> 31);
            dst[x + offset + y * dst_linesize] = temp;
        }
        x += 8;
    }
}
}
