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
for (int y = 0; y < height; y++) {
    const uint8_t *d = dither[y & 7]; // Use modulo indexing for dither to support arbitrary height
    int src_offset = y * src_linesize;
    int dst_offset = y * dst_linesize;
    for (int x = 0; x < width; x += 8) {
        // Unroll the loop with consecutive memory access and precomputed offsets
        int temp;

        temp = ((src[src_offset + x + 0] << log2_scale) + d[0]) >> 6;
        dst[dst_offset + x + 0] = (temp & 256) ? ~(temp >> 31) : temp;

        temp = ((src[src_offset + x + 1] << log2_scale) + d[1]) >> 6;
        dst[dst_offset + x + 1] = (temp & 256) ? ~(temp >> 31) : temp;

        temp = ((src[src_offset + x + 2] << log2_scale) + d[2]) >> 6;
        dst[dst_offset + x + 2] = (temp & 256) ? ~(temp >> 31) : temp;

        temp = ((src[src_offset + x + 3] << log2_scale) + d[3]) >> 6;
        dst[dst_offset + x + 3] = (temp & 256) ? ~(temp >> 31) : temp;

        temp = ((src[src_offset + x + 4] << log2_scale) + d[4]) >> 6;
        dst[dst_offset + x + 4] = (temp & 256) ? ~(temp >> 31) : temp;

        temp = ((src[src_offset + x + 5] << log2_scale) + d[5]) >> 6;
        dst[dst_offset + x + 5] = (temp & 256) ? ~(temp >> 31) : temp;

        temp = ((src[src_offset + x + 6] << log2_scale) + d[6]) >> 6;
        dst[dst_offset + x + 6] = (temp & 256) ? ~(temp >> 31) : temp;

        temp = ((src[src_offset + x + 7] << log2_scale) + d[7]) >> 6;
        dst[dst_offset + x + 7] = (temp & 256) ? ~(temp >> 31) : temp;
    }
}
}
