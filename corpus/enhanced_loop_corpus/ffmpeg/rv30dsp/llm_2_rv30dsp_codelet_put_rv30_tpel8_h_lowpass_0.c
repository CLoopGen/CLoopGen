#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int C1;
extern  int C2;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize src and dst accesses to process data in a more cache-friendly, consecutive manner
    // by unrolling and reordering computations to minimize stride-based jumps.
    uint8_t *src_line = src;
    uint8_t *dst_line = dst;
    for (i = 0; i < h; i++) {
        const uint8_t *s = src_line;
        uint8_t *d = dst_line;
        // Process 8 outputs using locally cached pointers for sequential access
        d[0] = cm[(-(s[-1] + s[2]) + s[0] * C1 + s[1] * C2 + 8) >> 4];
        d[1] = cm[(-(s[0] + s[3]) + s[1] * C1 + s[2] * C2 + 8) >> 4];
        d[2] = cm[(-(s[1] + s[4]) + s[2] * C1 + s[3] * C2 + 8) >> 4];
        d[3] = cm[(-(s[2] + s[5]) + s[3] * C1 + s[4] * C2 + 8) >> 4];
        d[4] = cm[(-(s[3] + s[6]) + s[4] * C1 + s[5] * C2 + 8) >> 4];
        d[5] = cm[(-(s[4] + s[7]) + s[5] * C1 + s[6] * C2 + 8) >> 4];
        d[6] = cm[(-(s[5] + s[8]) + s[6] * C1 + s[7] * C2 + 8) >> 4];
        d[7] = cm[(-(s[6] + s[9]) + s[7] * C1 + s[8] * C2 + 8) >> 4];
        dst_line += dstStride;
        src_line += srcStride;
    }
}
