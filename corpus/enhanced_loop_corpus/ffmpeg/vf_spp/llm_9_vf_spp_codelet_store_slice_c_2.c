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
for (int y = 0; y < height; y += 2) {
    const uint8_t *d0 = dither[y % 8];
    const uint8_t *d1 = dither[(y + 1) % 8];
    for (int x = 0; x < width; x += 4) {
        // Process two rows and four columns per iteration
        for (int dy = 0; dy < 2 && (y + dy) < height; dy++) {
            const uint8_t *d = (dy == 0) ? d0 : d1;
            for (int dx = 0; dx < 4 && (x + dx) < width; dx++) {
                int temp = ((src[(x + dx) + (y + dy) * src_linesize] << log2_scale) + d[(x + dx) % 8]) >> 6;
                if (temp & 256)
                    temp = ~(temp >> 31);
                dst[(x + dx) + (y + dy) * dst_linesize] = temp;
            }
        }
    }
}
}
