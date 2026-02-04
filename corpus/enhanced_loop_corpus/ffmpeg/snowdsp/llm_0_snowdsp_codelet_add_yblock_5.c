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



void loop() {
    for (y = 0; y < b_h; y++) {
        const uint8_t *obmc1 = obmc + y * obmc_stride;
        const uint8_t *obmc2 = obmc1 + (obmc_stride >> 1);
        const uint8_t *obmc3 = obmc1 + obmc_stride * (obmc_stride >> 1);
        const uint8_t *obmc4 = obmc3 + (obmc_stride >> 1);
        x = 0;
        for (; x < b_w; x += 2) {
            int v1 = obmc1[x] * block[3][x + y * src_stride] +
                     obmc2[x] * block[2][x + y * src_stride] +
                     obmc3[x] * block[1][x + y * src_stride] +
                     obmc4[x] * block[0][x + y * src_stride];
            int v2 = 0;
            if (x + 1 < b_w) {
                v2 = obmc1[x+1] * block[3][x+1 + y * src_stride] +
                     obmc2[x+1] * block[2][x+1 + y * src_stride] +
                     obmc3[x+1] * block[1][x+1 + y * src_stride] +
                     obmc4[x+1] * block[0][x+1 + y * src_stride];
            }
            v1 <<= 8 - 8;
            v2 <<= 8 - 8;
            if (4 != 8) {
                v1 >>= 8 - 4;
                v2 >>= 8 - 4;
            }
            if (add) {
                v1 += dst[x + y * dst_stride];
                v1 = (v1 + (1 << (4 - 1))) >> 4;
                if (v1 & (~255))
                    v1 = ~(v1 >> 31);
                dst8[x + y * src_stride] = v1;

                if (x + 1 < b_w) {
                    v2 += dst[x+1 + y * dst_stride];
                    v2 = (v2 + (1 << (4 - 1))) >> 4;
                    if (v2 & (~255))
                        v2 = ~(v2 >> 31);
                    dst8[x+1 + y * src_stride] = v2;
                }
            } else {
                dst[x + y * dst_stride] -= v1;
                if (x + 1 < b_w)
                    dst[x+1 + y * dst_stride] -= v2;
            }
        }
    }
}
