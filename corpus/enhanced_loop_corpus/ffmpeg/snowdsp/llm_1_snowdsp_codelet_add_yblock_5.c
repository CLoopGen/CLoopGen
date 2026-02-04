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
        for (x = 0; x < b_w; x++) {
            const uint8_t *obmc1 = obmc + y * obmc_stride;
            const uint8_t *obmc2 = obmc1 + (obmc_stride >> 1);
            const uint8_t *obmc3 = obmc1 + obmc_stride * (obmc_stride >> 1);
            const uint8_t *obmc4 = obmc3 + (obmc_stride >> 1);
            int v = obmc1[x] * block[3][x + y * src_stride] +
                    obmc2[x] * block[2][x + y * src_stride] +
                    obmc3[x] * block[1][x + y * src_stride] +
                    obmc4[x] * block[0][x + y * src_stride];
            v <<= 8 - 8;
            if (4 != 8) {
                v >>= 8 - 4;
            }
            if (add) {
                v += dst[x + y * dst_stride];
                v = (v + (1 << (4 - 1))) >> 4;
                if (v & (~255))
                    v = ~(v >> 31);
                dst8[x + y * src_stride] = v;
            } else {
                dst[x + y * dst_stride] -= v;
            }
        }
    }
}
