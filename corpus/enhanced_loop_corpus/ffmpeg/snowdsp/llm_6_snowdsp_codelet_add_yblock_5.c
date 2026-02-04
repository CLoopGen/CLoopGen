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
    const int idx_base = y * src_stride;
    for (x = 0; x < b_w; x++) {
        int v1 = obmc1[x] * block[3][x + idx_base];
        int v2 = obmc2[x] * block[2][x + idx_base];
        int v3 = obmc3[x] * block[1][x + idx_base];
        int v4 = obmc4[x] * block[0][x + idx_base];
        int v = v1 + v2 + v3 + v4;
        v <<= 8 - 8;
        if (4 != 8) {
            v >>= 8 - 4;
        }
        if (add) {
            int temp = dst_row[x];
            v += temp;
            v = (v + (1 << (4 - 1))) >> 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst8_row[x] = (uint8_t)v;
        } else {
            dst_row[x] -= v;
        }
    }
}
}
