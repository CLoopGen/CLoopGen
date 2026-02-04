#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *dst;
extern uint8_t *dst8;
extern  uint8_t *obmc;
extern int b_w;
extern int b_h;
extern int dst_stride;
extern int src_stride;
extern int obmc_stride;
extern int add;
extern uint8_t *block[4];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < b_h; y++) {
    const uint8_t *obmc1 = obmc + y * obmc_stride;
    const uint8_t *obmc2 = obmc1 + (obmc_stride >> 1);
    const uint8_t *obmc3 = obmc1 + obmc_stride * (obmc_stride >> 1);
    const uint8_t *obmc4 = obmc3 + (obmc_stride >> 1);
    int offset_y = y * src_stride;
    int dst_offset_y = y * dst_stride;
    for (x = 0; x < b_w; x++) {
        int v = obmc1[x] * block[3][x + offset_y] +
                obmc2[x] * block[2][x + offset_y] +
                obmc3[x] * block[1][x + offset_y] +
                obmc4[x] * block[0][x + offset_y];
        v >>= 0; // Redundant shift, kept for symmetry

        if (add) {
            int temp = dst[x + dst_offset_y];
            v += temp;
            v = (v + (1 << 3)) >> 4;

            // Clamp using arithmetic without branching
            v = (v & (~255)) ? (v >> 31) | 128 : v; // Simplified saturation hint
            v = (v > 255) ? 255 : ((v < 0) ? 0 : v);

            dst8[x + offset_y] = (uint8_t)v;
        } else {
            // Always perform subtraction when add is false
            dst[x + dst_offset_y] -= v;
        }
    }
}
}
