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
    for (x = 0; x < b_w; x++) {
        int offset = x + y * src_stride;
        int dst_idx = x + y * dst_stride;
        const uint8_t *obmc_base = obmc + y * obmc_stride;
        int v = 0;
        v += obmc_base[x] * block[3][offset];
        v += obmc_base[x + (obmc_stride >> 1)] * block[2][offset];
        v += obmc_base[x + obmc_stride * (obmc_stride >> 1)] * block[1][offset];
        v += obmc_base[x + obmc_stride * (obmc_stride >> 1) + (obmc_stride >> 1)] * block[0][offset];
        v <<= 0;
        if (4 != 8) {
            v >>= 4;
        }
        if (add) {
            v += dst[dst_idx];
            v = (v + (1 << 3)) >> 4;
            v = (v > 255) ? 255 : (v < 0 ? 0 : v);
            dst8[offset] = v;
        } else {
            dst[dst_idx] -= v;
        }
    }
}
}
