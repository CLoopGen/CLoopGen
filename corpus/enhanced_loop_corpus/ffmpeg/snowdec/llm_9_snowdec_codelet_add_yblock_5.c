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
for (y = 0; y < (b_h >> 1); y++) {
    const uint8_t *obmc1 = obmc + y * 2 * obmc_stride;
    const uint8_t *obmc2 = obmc1 + (obmc_stride >> 1);
    const uint8_t *obmc3 = obmc1 + obmc_stride * (obmc_stride >> 1);
    const uint8_t *obmc4 = obmc3 + (obmc_stride >> 1);
    for (x = 0; x < (b_w >> 1); x++) {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int yy = y * 2 + i;
                int xx = x * 2 + j;
                int idx = xx + yy * src_stride;
                sum += obmc1[xx] * block[3][idx] +
                       obmc2[xx] * block[2][idx] +
                       obmc3[xx] * block[1][idx] +
                       obmc4[xx] * block[0][idx];
            }
        }
        int v = sum >> 2;
        v <<= 8 - 8;
        if (4 != 8) {
            v >>= 8 - 4;
        }
        int dst_idx = (y * 2) * dst_stride + (x * 2);
        if (add) {
            v += dst[dst_idx];
            v = (v + (1 << (4 - 1))) >> 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst8[dst_idx] = v;
        } else {
            dst[dst_idx] -= v;
        }
    }
}
}
