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
    const uint8_t *d = dither[y % 8];
    for (x = 0; x < width; x += 8) {
        for (int k = 0; k < 8; k++) {
            int offset = x + y * src_linesize + k;
            int dst_offset = x + y * dst_linesize + k;
            int temp = ((src[offset] << log2_scale) + (d[k] >> 1)) >> 5;
            if (temp & mask) {
                temp = ~(temp >> 31);
            } else {
                if (k % 2 == 0) continue;
            }
            dst[dst_offset] = temp;
        }
    }
}
}
