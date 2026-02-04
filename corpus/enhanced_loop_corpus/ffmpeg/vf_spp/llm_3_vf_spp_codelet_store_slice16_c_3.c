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



void loop() {
    // Strided memory access pattern: process one column at a time (column-major traversal)
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            const uint8_t *d = dither[y & 7]; // Bound-check dither index
            int src_idx = y * src_linesize + x;
            int dst_idx = y * dst_linesize + x;
            int temp = ((src[src_idx] << log2_scale) + (d[x & 7] >> 1)) >> 5;
            if (temp & mask)
                temp = ~(temp >> 31);
            dst[dst_idx] = temp;
        }
    }
}
