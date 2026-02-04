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
    const uint8_t *obmc1 = obmc + (y << 1) * obmc_stride;
    const uint8_t *obmc2 = obmc1 + (obmc_stride >> 1);
    const uint8_t *obmc3 = obmc1 + obmc_stride * (obmc_stride >> 1);
    const uint8_t *obmc4 = obmc3 + (obmc_stride >> 1);
    for (x = 0; x < (b_w >> 1); x++) {
        int idx = (x << 1) + y * src_stride;
        int v = (obmc1[x] * block[3][idx]) +
                (obmc2[x] * block[2][idx]) +
                (obmc3[x] * block[1][idx]) +
                (obmc4[x] * block[0][idx]);
        v >>= 0;
        if (add) {
            v += dst[idx];
            v = (v + 3) >> 2;
            v = (v < 0) ? 0 : (v > 255 ? 255 : v);
            dst8[idx] = v;
        } else {
            dst[idx] -= v;
        }
    }
}
}
