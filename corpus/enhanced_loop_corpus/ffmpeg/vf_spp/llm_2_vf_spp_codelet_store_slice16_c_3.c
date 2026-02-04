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
    for (y = 0; y < height; y++) {
        const uint8_t *d = dither[y & 7]; // Use modulo indexing for dither to ensure bounds safety
        int offset = y * src_linesize;
        int dst_offset = y * dst_linesize;
        for (x = 0; x < width; x += 8) {
            // Unroll the inner loop with direct and consecutive memory accesses
            int temp0 = ((src[offset + x + 0] << log2_scale) + (d[0] >> 1)) >> 5;
            int temp1 = ((src[offset + x + 1] << log2_scale) + (d[1] >> 1)) >> 5;
            int temp2 = ((src[offset + x + 2] << log2_scale) + (d[2] >> 1)) >> 5;
            int temp3 = ((src[offset + x + 3] << log2_scale) + (d[3] >> 1)) >> 5;
            int temp4 = ((src[offset + x + 4] << log2_scale) + (d[4] >> 1)) >> 5;
            int temp5 = ((src[offset + x + 5] << log2_scale) + (d[5] >> 1)) >> 5;
            int temp6 = ((src[offset + x + 6] << log2_scale) + (d[6] >> 1)) >> 5;
            int temp7 = ((src[offset + x + 7] << log2_scale) + (d[7] >> 1)) >> 5;

            dst[dst_offset + x + 0] = (temp0 & mask) ? ~(temp0 >> 31) : temp0;
            dst[dst_offset + x + 1] = (temp1 & mask) ? ~(temp1 >> 31) : temp1;
            dst[dst_offset + x + 2] = (temp2 & mask) ? ~(temp2 >> 31) : temp2;
            dst[dst_offset + x + 3] = (temp3 & mask) ? ~(temp3 >> 31) : temp3;
            dst[dst_offset + x + 4] = (temp4 & mask) ? ~(temp4 >> 31) : temp4;
            dst[dst_offset + x + 5] = (temp5 & mask) ? ~(temp5 >> 31) : temp5;
            dst[dst_offset + x + 6] = (temp6 & mask) ? ~(temp6 >> 31) : temp6;
            dst[dst_offset + x + 7] = (temp7 & mask) ? ~(temp7 >> 31) : temp7;
        }
    }
}
