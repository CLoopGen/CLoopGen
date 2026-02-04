#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access, we reorganize the memory layout to write data consecutively in dst.
    // We assume dst is now arranged to accept 4 pixels of RGB (3 bytes each) in a flat sequence.
    uint8_t *d = dst;
    const uint8_t *s = src;

    for (i = 0; i < width; i += 2) {
        uint8_t s_00 = s[(0) * src_stride + 0];
        uint8_t s_01 = s[(0) * src_stride + 1];
        uint8_t s_10 = s[(1) * src_stride + 0];
        uint8_t s_11 = s[(1) * src_stride + 1];

        // Write 4 output pixels' R components consecutively
        d[0] = s_11;
        d[1] = s_11;
        d[2] = s_11;
        d[3] = s_11;

        // G components: average or direct
        d[4] = s_01;
        d[5] = ((unsigned int)s_01 + (unsigned int)s_10) >> 1;
        d[6] = ((unsigned int)s_01 + (unsigned int)s_10) >> 1;
        d[7] = s_10;

        // B components: all set to s_00
        d[8] = s_00;
        d[9] = s_00;
        d[10] = s_00;
        d[11] = s_00;

        s += 2;
        d += 12;  // Each iteration writes 4×3 = 12 bytes
    }

    src = (uint8_t*)s;
    dst = d;
}
