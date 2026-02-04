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
    IDWTELEM *dst_row = dst + y * dst_stride;
    uint8_t *dst8_row = dst8 + y * src_stride;
    const uint8_t *blk0_row = block[0] + y * src_stride;
    const uint8_t *blk1_row = block[1] + y * src_stride;
    const uint8_t *blk2_row = block[2] + y * src_stride;
    const uint8_t *blk3_row = block[3] + y * src_stride;

    for (x = 0; x < b_w; x++) {
        int v0 = obmc1[x] * blk3_row[x];
        int v1 = obmc2[x] * blk2_row[x];
        int v2 = obmc3[x] * blk1_row[x];
        int v3 = obmc4[x] * blk0_row[x];

        int v = v0 + v1 + v2 + v3;
        v <<= 0;
        if (4 != 8) {
            v >>= 4;
        }

        if (add) {
            int temp = dst_row[x];
            v += temp;
            v = (v + (1 << 3)) >> 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst8_row[x] = (uint8_t)v;
        } else {
            dst_row[x] -= v;
        }
    }
}
}
