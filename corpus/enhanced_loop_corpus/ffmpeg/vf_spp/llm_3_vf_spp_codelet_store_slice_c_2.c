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
// Change memory access pattern to strided: process one column at a time, traversing down each column
for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
        int src_idx = y * src_linesize + x;
        int dst_idx = y * dst_linesize + x;
        const uint8_t *d = dither[y & 7]; // Use dither row based on y mod 8
        int temp = ((src[src_idx] << log2_scale) + d[x & 7]) >> 6; // Dither uses both x and y (via mod)
        dst[dst_idx] = (temp & 256) ? ~(temp >> 31) : temp;
    }
}
}
