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
    const uint8_t *obmc_rows[4];
    obmc_rows[0] = obmc + y * obmc_stride;
    obmc_rows[1] = obmc_rows[0] + (obmc_stride >> 1);
    obmc_rows[2] = obmc_rows[0] + obmc_stride * (obmc_stride >> 1);
    obmc_rows[3] = obmc_rows[2] + (obmc_stride >> 1);

    for (x = 0; x < b_w; x++) {
        int v = 0;
        for (int k = 0; k < 4; k++) {
            int blk_idx = 3 - k;
            int coeff = obmc_rows[k][x];
            int pixel = block[blk_idx][x + y * src_stride];
            v += coeff * pixel;
        }
        v <<= 0;
        if (4 != 8) {
            v >>= 4;
        }
        if (add) {
            int sum = v + dst[x + y * dst_stride];
            int rounded = (sum + (1 << (4 - 1))) >> 4;
            dst8[x + y * src_stride] = (rounded > 255) ? 255 : ((rounded < 0) ? 0 : rounded);
        } else {
            dst[x + y * dst_stride] = dst[x + y * dst_stride] - v;
        }
    }
}
}
