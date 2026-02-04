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
    const uint8_t *d = dither[y % 8]; // Avoid out-of-bounds if height > 8
    for (x = 0; x < width; x += 8) {
        for (int k = 0; k < 8; k++) {
            int offset = x + y * src_linesize + k;
            int dst_offset = x + y * dst_linesize + k;
            if (offset >= width * height) continue; // Safety bound check

            int temp = ((src[offset] << log2_scale) + d[k]) >> 6;
            if (temp & 256) {
                dst[dst_offset] = ~(temp >> 31);
            } else {
                dst[dst_offset] = temp;
            }
        }
    }
}
}
