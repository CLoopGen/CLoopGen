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
    int x_inner;
    for (x = 0; x < b_w; x += 2) {
        for (int unroll = 0; unroll < 2; unroll++) {
            x_inner = x + unroll;
            if (x_inner >= b_w) continue;
            int v = obmc1[x_inner] * block[3][x_inner + y * src_stride] +
                    obmc2[x_inner] * block[2][x_inner + y * src_stride] +
                    obmc3[x_inner] * block[1][x_inner + y * src_stride] +
                    obmc4[x_inner] * block[0][x_inner + y * src_stride];
            v <<= 0;
            if (4 != 8) {
                v >>= 4;
            }
            if (add) {
                v += dst[x_inner + y * dst_stride];
                v = (v + 8) >> 4;
                if (v & (~255))
                    v = ~(v >> 31);
                dst8[x_inner + y * src_stride] = v;
            } else {
                dst[x_inner + y * dst_stride] -= v;
            }
        }
    }
}
}
